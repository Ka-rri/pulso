#include "logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace pulso::utils::logging {

namespace {

std::string obtenerTimestamp() {
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempo = std::chrono::system_clock::to_time_t(ahora);

    std::tm tiempoLocal{};

#ifdef _WIN32
    localtime_s(&tiempoLocal, &tiempo);
#else
    localtime_r(&tiempo, &tiempoLocal);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tiempoLocal, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

std::string nivelATexto(Nivel nivel) {
    switch (nivel) {
        case Nivel::DEBUG:
            return "DEBUG";
        case Nivel::INFO:
            return "INFO";
        case Nivel::WARN:
            return "WARN";
        case Nivel::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

} // namespace

Logger& Logger::instancia() {
    static Logger instancia;
    return instancia;
}

void Logger::configurar(Nivel nivelMinimo) {
    nivelMinimo_ = nivelMinimo;
}

void Logger::debug(const std::string& mensaje) {
    if (Nivel::DEBUG < nivelMinimo_) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);

    std::cerr << "[" << obtenerTimestamp() << "] "
              << "[DEBUG] "
              << mensaje << '\n';
}

void Logger::info(const std::string& mensaje) {
    if (Nivel::INFO < nivelMinimo_) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);

    std::cerr << "[" << obtenerTimestamp() << "] "
              << "[INFO] "
              << mensaje << '\n';
}

void Logger::warn(const std::string& mensaje) {
    if (Nivel::WARN < nivelMinimo_) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);

    std::cerr << "[" << obtenerTimestamp() << "] "
              << "[WARN] "
              << mensaje << '\n';
}

void Logger::error(const std::string& mensaje) {
    if (Nivel::ERROR < nivelMinimo_) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);

    std::cerr << "[" << obtenerTimestamp() << "] "
              << "[ERROR] "
              << mensaje << '\n';
}

} // namespace pulso::utils::logging