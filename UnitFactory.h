#ifndef UNIT_FACTORY_H
#define UNIT_FACTORY_H

#include "Unit.h"
#include <memory>
#include <string>

enum class UnitType {
    Swordsman, Spearman,
    Archer, Crossbowman,
    Horseman, Knight
};

class UnitFactory {
public:
    virtual ~UnitFactory() = default;
    virtual std::unique_ptr<Unit> createUnit(UnitType type) = 0;
};

class BasicUnitFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(UnitType type) override;
};

#endif