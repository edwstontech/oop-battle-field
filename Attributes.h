#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <string>

class Health {
public:
    int current;
    int max;
    Health(int max_hp = 100) : max(max_hp), current(max_hp) {}
    bool isAlive() const { return current > 0; }
    void takeDamage(int dmg) {
        current = std::max(0, current - dmg);
    }
    std::string toString() const {
        return "HP: " + std::to_string(current) + "/" + std::to_string(max);
    }
};

class AttackPower {
public:
    int value;
    explicit AttackPower(int atk = 10) : value(atk) {}
    std::string toString() const { return "Attack: " + std::to_string(value); }
};

class Armor {
public:
    int value;
    explicit Armor(int def = 5) : value(def) {}
    std::string toString() const { return "Armor: " + std::to_string(value); }
};

#endif