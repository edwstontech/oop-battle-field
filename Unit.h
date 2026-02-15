#ifndef UNIT_H
#define UNIT_H

#include "Attributes.h"
#include <memory>
#include <string>

class Field;  // forward declaration

class Unit {
protected:
    Health health;
    AttackPower attack;
    Armor armor;
    int pos_x = -1;
    int pos_y = -1;
    std::string type_name;

public:
    Unit(Health h, AttackPower a, Armor ar, std::string name = "Unit")
        : health(h), attack(a), armor(ar), type_name(std::move(name)) {
    }

    virtual ~Unit() = default;

    // копирование
    Unit(const Unit& other)
        : health(other.health),
        attack(other.attack),
        armor(other.armor),
        pos_x(other.pos_x),
        pos_y(other.pos_y),
        type_name(other.type_name) {
    }

    Unit& operator=(const Unit& other) {
        if (this != &other) {
            health = other.health;
            attack = other.attack;
            armor = other.armor;
            pos_x = other.pos_x;
            pos_y = other.pos_y;
            type_name = other.type_name;
        }
        return *this;
    }

    // перемещение
    Unit(Unit&& other) noexcept
        : health(std::move(other.health)),
        attack(std::move(other.attack)),
        armor(std::move(other.armor)),
        pos_x(other.pos_x), pos_y(other.pos_y),
        type_name(std::move(other.type_name)) {
        other.pos_x = -1; other.pos_y = -1;
    }

    Unit& operator=(Unit&& other) noexcept {
        if (this != &other) {
            health = std::move(other.health);
            attack = std::move(other.attack);
            armor = std::move(other.armor);
            pos_x = other.pos_x; pos_y = other.pos_y;
            type_name = std::move(other.type_name);
            other.pos_x = -1; other.pos_y = -1;
        }
        return *this;
    }

    virtual std::unique_ptr<Unit> clone() const = 0;

    virtual int moveRange() const = 0;

    bool moveTo(int x, int y, Field& field);

    std::string getInfo() const;

    int getX() const { return pos_x; }
    int getY() const { return pos_y; }
    void setPosition(int x, int y) { pos_x = x; pos_y = y; }

    Health& getHealth() { return health; }
    const std::string& getType() const { return type_name; }

    virtual int getAttackDamage() const { return attack.value; }
    virtual int getArmorReduction() const { return armor.value; }
};

#endif