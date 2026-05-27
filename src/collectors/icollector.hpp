#pragma once
#include <string>
#include <vector>
#include "../core/types.hpp"

namespace pulso::collectors {

/**
 * @brief Interfaz base para todos los colectores de métricas del sistema.
 *
 * Todo collector debe implementar nombre() y recolectar() para integrarse
 * al pipeline de monitoreo de Pulso.
 */
class ICollector {
public:
    virtual ~ICollector() = default;

    /// @brief Retorna el nombre identificador del collector. Ej: "disk", "cpu".
    virtual std::string nombre() const = 0;

    /// @brief Recolecta las métricas del sistema y las retorna como vector.
    /// @return Vector de Metrica con los valores medidos.
    virtual std::vector<pulso::core::Metrica> recolectar() = 0;
};

} // namespace pulso::collectors