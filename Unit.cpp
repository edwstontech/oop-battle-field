#include "Unit.h"
#include "Field.h"
#include <cmath>  // для abs
#include <string>

std::string Unit::getInfo() const {
    return type_name + " at (" + std::to_string(pos_x) + ", " + std::to_string(pos_y) + ") " +
        health.toString() + " " + attack.toString() + " " + armor.toString();
}

bool Unit::moveTo(int x, int y, Field& field) {
    if (pos_x == -1 || pos_y == -1) return false;  // не на поле

    int dx = std::abs(x - pos_x);
    int dy = std::abs(y - pos_y);
    if (dx + dy > moveRange()) return false;  // Manhattan distance check

    if (x < 0 || x >= field.getWidth() || y < 0 || y >= field.getHeight()) return false;

    if (field.getUnitAt(x, y)) return false;  // занято

    pos_x = x;
    pos_y = y;
    return true;
}