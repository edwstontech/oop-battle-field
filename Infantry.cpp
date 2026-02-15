#include "Infantry.h"

Swordsman::Swordsman()
    : Unit(Health(120), AttackPower(18), Armor(6), "Swordsman") {
}

std::unique_ptr<Unit> Swordsman::clone() const {
    return std::make_unique<Swordsman>(*this);
}

Spearman::Spearman()
    : Unit(Health(100), AttackPower(22), Armor(4), "Spearman") {
}

std::unique_ptr<Unit> Spearman::clone() const {
    return std::make_unique<Spearman>(*this);
}