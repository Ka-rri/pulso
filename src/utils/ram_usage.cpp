#include "ram_usage.hpp"

#include <fstream>
#include <string>
#include <stdexcept>

double getRAMUsage() {
    std::ifstream file("/proc/meminfo");

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir /proc/meminfo");
    }

    std::string line;

    unsigned long long memTotal = 0;
    unsigned long long memAvailable = 0;

    while (std::getline(file, line)) {

        if (line.find("MemTotal:") == 0) {

            std::string value = line.substr(10);

            memTotal = std::stoull(value);
        }

        if (line.find("MemAvailable:") == 0) {

            std::string value = line.substr(14);

            memAvailable = std::stoull(value);
        }
    }

    if (memTotal == 0 || memAvailable == 0) {
        throw std::runtime_error("No se pudieron leer datos de memoria");
    }

    return ((memTotal - memAvailable) * 100.0) / memTotal;
}