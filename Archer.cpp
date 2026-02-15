#include "Archer.h"

Archer::Archer()
    : Unit(Health(80), AttackPower(15), Armor(2), "Archer") {
}

std::unique_ptr<Unit> Archer::clone() const {
    return std::make_unique<Archer>(*this);
}

Crossbowman::Crossbowman()
    : Unit(Health(90), AttackPower(20), Armor(3), "Crossbowman") {
}

std::unique_ptr<Unit> Crossbowman::clone() const {
    return std::make_unique<Crossbowman>(*this);
}