#include "Cavalry.h"

Horseman::Horseman()
    : Unit(Health(110), AttackPower(16), Armor(5), "Horseman") {
}

std::unique_ptr<Unit> Horseman::clone() const {
    return std::make_unique<Horseman>(*this);
}

Knight::Knight()
    : Unit(Health(140), AttackPower(24), Armor(10), "Knight") {
}

std::unique_ptr<Unit> Knight::clone() const {
    return std::make_unique<Knight>(*this);
}