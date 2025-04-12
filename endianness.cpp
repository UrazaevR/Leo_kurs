#include <arpa/inet.h> // Для Linux и macOS
#include <cstdint>
#include <iostream> // Для отладочного вывода (можно убрать потом)

// Реализация htonll (Host To Network Long Long)
uint64_t htonll(uint64_t value) {
    uint64_t result = 0;
    uint32_t high_part = htonl((uint32_t)(value >> 32));
    uint32_t low_part = htonl((uint32_t)(value & 0xFFFFFFFF));

    result = ((uint64_t)low_part << 32) | high_part;
    return result;
}

// Реализация ntohll (Network To Host Long Long)
uint64_t ntohll(uint64_t value) {
    uint64_t result = 0;
    uint32_t low_part = ntohl((uint32_t)(value >> 32));
    uint32_t high_part = ntohl((uint32_t)(value & 0xFFFFFFFF));

    result = ((uint64_t)high_part << 32) | low_part;
    return result;
}