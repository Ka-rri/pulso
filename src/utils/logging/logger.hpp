#pragma once

#include <mutex>
#include <string>

namespace pulso::utils::logging {

enum class Nivel { DEBUG, INFO, WARN, ERROR };

class Logger {
public:
    static Logger& instancia();

    void configurar(Nivel nivelMinimo);

    void debug(const std::string& mensaje);
    void info(const std::string& mensaje);
    void warn(const std::string& mensaje);
    void error(const std::string& mensaje);

private:
    Logger() = default;

    Nivel nivelMinimo_ = Nivel::INFO;
    std::mutex mutex_;
};

} // namespace pulso::utils::logging