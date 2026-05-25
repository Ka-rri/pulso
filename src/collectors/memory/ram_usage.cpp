#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;
struct RamUsage {
    long long total;
    long long used;
    long long available;
};

RamUsage getRamUsage() {
    ifstream file("/proc/meminfo");

    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo /proc/meminfo: verifique permisos y disponibilidad del sistema");
    }

    string line;
    long long memTotal = 0;
    long long memAvailable = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        string key;
        long long value;

        iss >> key >> value;

        if (key == "MemTotal:") {
            memTotal = value;
        }

        if (key == "MemAvailable:") {
            memAvailable = value;
        }
    }

    if (memTotal == 0 || memAvailable == 0) {
        throw runtime_error("No se encontraron las claves MemTotal o MemAvailable en /proc/meminfo");
    memTotal *= 1024;
    memAvailable *= 1024;

    long long memUsed = memTotal - memAvailable;

    return {memTotal, memUsed, memAvailable};
}