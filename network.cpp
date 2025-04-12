#include <cstring>
#include <unistd.h>
#include <iostream>

#include "network.h"
#include "exceptions.h"
#include "endianness.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <cryptopp/hex.h>
#include <cryptopp/md5.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>


std::string get_salt() { //функция для генерации соли
    char s[] = "0123456789ABCDEF";
    std::string ans = "";
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        ans += s[rand() % 16];
    }
    return ans;
}

std::string MD5_hash(const std::string& message) { //функция для хэщирования с помощью MD5
    using namespace CryptoPP;
    Weak1::MD5 hash;
    std::string digest;
    StringSource(message, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
    return digest;
}

// Конструктор
NetworkManager::NetworkManager(const std::string &address, uint16_t port)
    : address(address), port(port), socket(-1) {}

std::string &NetworkManager::getAddress()
{
    return this->address;
};
uint16_t &NetworkManager::getPort()
{
    return this->port;
};
// Метод для установки соединения
void NetworkManager::conn()
{
    this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (this->socket < 0)
    {
        throw NetworkException("Failed to create socket", "NetworkManager.conn()");
    }

    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(this->port);

    if (inet_pton(AF_INET, this->address.c_str(), &server_addr.sin_addr) <= 0)
        throw NetworkException("Invalid address/ Address not supported", "NetworkManager.conn()");

    if (connect(this->socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        throw NetworkException("Connection failed", "NetworkManager.conn()");
}

// Метод для аутентификации
void NetworkManager::auth(const std::string &login, const std::string &password)
{
    //Генерация соли
    std::string salt = get_salt();

    // Вычисление хеша с использованием CryptoPP
    std::string hash_hex = MD5_hash(salt + password);
    
    //Формирование сообщения для аутентификации
    std::string message = login + salt + hash_hex;

    // Отправка хеша серверу
    if (send(this->socket, message.c_str(), message.size(), 0) < 0)
    {
        throw AuthException("Failed to send hash", "NetworkManager.auth()");
    }

    // Получение ответа от сервера
    char response[1024];
    int response_length = recv(this->socket, response, sizeof(response) - 1, 0);
    if (response_length < 0)
    {
        throw AuthException("Failed to receive auth response", "NetworkManager.auth()");
    }

    response[response_length] = '\0';
    if (std::string(response) != "OK")
    {
        throw AuthException("Authentication failed", "NetworkManager.auth()");
    }
}

    std::vector<uint64_t> NetworkManager::calc(const std::vector<std::vector<uint64_t>>& data) {
        // Передача количества векторов
        uint64_t num_vectors = data.size();
        uint64_t num_vectors_net = htonll(num_vectors);  // Конвертируем в network byte order

        if (send(this->socket, &num_vectors_net, sizeof(num_vectors_net), 0) < 0) {
            throw NetworkException("Failed to send number of vectors", "NetworkManager.calc()");
        }

        // Передача каждого вектора
        for (const auto& vec : data) {
            uint64_t vec_size = vec.size();
            std::cout << "Client: vec_size before htonll: " << vec_size << std::endl;

            uint64_t vec_size_net = htonll(vec_size); // Конвертируем в network byte order
            std::cout << "Client: vec_size_net after htonll: " << vec_size_net << std::endl;

            if (send(this->socket, &vec_size_net, sizeof(vec_size_net), 0) < 0) {
                throw NetworkException("Failed to send vector size", "NetworkManager.calc()");
            }

            std::vector<uint64_t> vec_net(vec.size());
            for (size_t i = 0; i < vec.size(); ++i) {
                vec_net[i] = htonll(vec[i]); // Конвертируем каждый элемент вектора
            }


            if (send(this->socket, vec_net.data(), vec_size * sizeof(uint64_t), 0) < 0) {
                throw NetworkException("Failed to send vector data", "NetworkManager.calc()");
            }
        }

        // Получение результатов
        std::vector<uint64_t> results(num_vectors);
        for (uint64_t i = 0; i < num_vectors; ++i) {
            uint64_t result_net;
            if (recv(this->socket, &result_net, sizeof(uint64_t), 0) < 0) {
                throw NetworkException("Failed to receive result", "NetworkManager.calc()");
            }
            results[i] = ntohll(result_net); // Конвертируем обратно в host byte order
        }

        // Логирование результата
        std::cout << "Log: \"NetworkManager.calc()\"\n";
        std::cout << "Results: {";
        for (const auto& val : results) {
            std::cout << val << ", ";
        }
        if (!results.empty()) {
            std::cout << "\b\b"; // Удалить последнюю запятую и пробел
        }
        std::cout << "}\n";

        return results;
    }

// Метод для закрытия соединения
void NetworkManager::close()
{
    if (this->socket >= 0)
    {
        ::close(this->socket);
        this->socket = -1;
    }
}
