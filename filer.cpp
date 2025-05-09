#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>
#include <cstring>
#include <type_traits>

// Ôóíêöèÿ äëÿ ïå÷àòè ñïðàâêè
void print_help() {
    std::cout << "Usage: filer -dt DATA_TYPE -ft FILE_TYPE -n COUNT -s SIZE -p PATH\n"
        << "Options:\n"
        << "  -dt DATA_TYPE   Type of data (e.g., uint16_t, int16_t, uint64_t, int32_t, uint64_t, int64_t, float, double)\n"
        << "  -ft FILE_TYPE   File type: 'bin' or 'txt' (default: bin)\n"
        << "  -n COUNT        Number of vectors (default: 3)\n"
        << "  -s SIZE         Size of each vector (default: 3)\n"
        << "  -p PATH         Path to the output file (default: input.[file_type])\n"
        << "  -h              Show this help message and exit\n";
}

// Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî çíà÷åíèÿ â äèàïàçîíå òèïà äàííûõ
template <typename T>
T generate_value() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int64_t> dis(std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
    T value;
    do {
        int64_t val = dis(gen);
        if (std::is_integral<T>::value) {
            value = static_cast<T>(val);
        }
        else {
            std::uniform_real_distribution<double> dis_double(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
            value = static_cast<T>(dis_double(gen));
        }
    } while (value < std::numeric_limits<T>::min() || value > std::numeric_limits<T>::max());
    return value;
}

// Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî âåêòîðà
template <typename T>
std::vector<T> generate_vector(uint64_t size) {
    std::vector<T> vec(size);
    for (auto& v : vec) {
        v = generate_value<T>();
    }
    return vec;
}

// Ôóíêöèÿ äëÿ çàïèñè â áèíàðíûé ôàéë
template <typename T>
void write_binary(std::ofstream& outfile, uint64_t count, uint64_t size) {
    outfile.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (uint64_t i = 0; i < count; ++i) {
        auto vec = generate_vector<T>(size);
        uint64_t vec_size = vec.size();
        outfile.write(reinterpret_cast<const char*>(&vec_size), sizeof(vec_size));
        outfile.write(reinterpret_cast<const char*>(vec.data()), vec.size() * sizeof(T));
    }
}

// Ôóíêöèÿ äëÿ çàïèñè â òåêñòîâûé ôàéë
template <typename T>
void write_text(std::ofstream& outfile, uint64_t count, uint64_t size) {
    outfile << count << "\n";
    for (uint64_t i = 0; i < count; ++i) {
        auto vec = generate_vector<T>(size);
        uint64_t vec_size = vec.size();
        outfile << vec_size << "\n"; // Çàïèñûâàåì ðàçìåð âåêòîðà ïåðåä êàæäûì âåêòîðîì
        for (const auto& v : vec) {
            outfile << v << " "; // Çàïèñûâàåì çíà÷åíèÿ áåç äîïîëíåíèÿ íóëÿìè
        }
        outfile << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::string data_type;
    std::string file_type = "bin"; // Çíà÷åíèå ïî óìîë÷àíèþ
    uint64_t count = 3;            // Çíà÷åíèå ïî óìîë÷àíèþ
    uint64_t size = 3;             // Çíà÷åíèå ïî óìîë÷àíèþ
    std::string file_path;

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-dt") == 0 && i + 1 < argc) {
            data_type = argv[++i];
        }
        else if (std::strcmp(argv[i], "-ft") == 0 && i + 1 < argc) {
            file_type = argv[++i];
        }
        else if (std::strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            count = std::stoul(argv[++i]);
        }
        else if (std::strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            size = std::stoul(argv[++i]);
        }
        else if (std::strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            file_path = argv[++i];
        }
        else if (std::strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        }
        else {
            print_help();
            return 1;
        }
    }

    // Óñòàíîâêà çíà÷åíèÿ ïî óìîë÷àíèþ äëÿ file_path, åñëè îíî íå áûëî óñòàíîâëåíî
    if (file_path.empty()) {
        file_path = "input." + file_type;
    }

    if (data_type.empty() || count == 0 || size == 0 || file_path.empty()) {
        print_help();
        return 1;
    }

    std::ofstream outfile;
    if (file_type == "bin") {
        outfile.open(file_path, std::ios::binary);
    }
    else if (file_type == "txt") {
        outfile.open(file_path);
    }

    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 1;
    }

    if (file_type == "bin") {
        if (data_type == "uint16_t") {
            write_binary<uint16_t>(outfile, count, size);
        }
        else if (data_type == "int16_t") {
            write_binary<int16_t>(outfile, count, size);
        }
        else if (data_type == "uint64_t") {
            write_binary<uint64_t>(outfile, count, size);
        }
        else if (data_type == "int32_t") {
            write_binary<int32_t>(outfile, count, size);
        }
        else if (data_type == "uint64_t") {
            write_binary<uint64_t>(outfile, count, size);
        }
        else if (data_type == "int64_t") {
            write_binary<int64_t>(outfile, count, size);
        }
        else if (data_type == "float") {
            write_binary<float>(outfile, count, size);
        }
        else if (data_type == "double") {
            write_binary<double>(outfile, count, size);
        }
        else {
            std::cerr << "Unsupported data type: " << data_type << std::endl;
            return 1;
        }
    }
    else if (file_type == "txt") {
        if (data_type == "uint16_t") {
            write_text<uint16_t>(outfile, count, size);
        }
        else if (data_type == "int16_t") {
            write_text<int16_t>(outfile, count, size);
        }
        else if (data_type == "uint64_t") {
            write_text<uint64_t>(outfile, count, size);
        }
        else if (data_type == "int32_t") {
            write_text<int32_t>(outfile, count, size);
        }
        else if (data_type == "uint64_t") {
            write_text<uint64_t>(outfile, count, size);
        }
        else if (data_type == "int64_t") {
            write_text<int64_t>(outfile, count, size);
        }
        else if (data_type == "float") {
            write_text<float>(outfile, count, size);
        }
        else if (data_type == "double") {
            write_text<double>(outfile, count, size);
        }
        else {
            std::cerr << "Unsupported data type: " << data_type << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Unsupported file type: " << file_type << std::endl;
        return 1;
    }

    outfile.close();
    std::cout << "File generated successfully: " << file_path << std::endl;
    return 0;
}
