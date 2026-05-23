#pragma once

#include "../../core/interfaces/icollector.hpp"
#include <vector>
#include <string>

class CollectorCPU : public ICollector {
public:
    std::string nombre() const override;
    std::vector<Metrica> recolectar() override;
};