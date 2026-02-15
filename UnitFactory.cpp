#include "UnitFactory.h"
#include "Infantry.h"
#include "Archer.h"
#include "Cavalry.h"
#include <stdexcept>

std::unique_ptr<Unit> BasicUnitFactory::createUnit(UnitType type) {
    switch (type) {
    case UnitType::Swordsman:    return std::make_unique<Swordsman>();
    case UnitType::Spearman:     return std::make_unique<Spearman>();
    case UnitType::Archer:       return std::make_unique<Archer>();
    case UnitType::Crossbowman:  return std::make_unique<Crossbowman>();
    case UnitType::Horseman:     return std::make_unique<Horseman>();
    case UnitType::Knight:       return std::make_unique<Knight>();
    default: throw std::invalid_argument("Unknown unit type");
    }
}