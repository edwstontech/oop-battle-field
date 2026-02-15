#include "Field.h"
#include <algorithm>  // для find_if
#include <string>
#include <utility>    // для std::move

Field::Field(int w, int h, size_t max) : width(w), height(h), max_units(max) {}

Field::Field(const Field& other) : width(other.width), height(other.height), max_units(other.max_units) {
    for (const auto& u : other.units) {
        auto clone = u->clone();
        clone->setPosition(u->getX(), u->getY());
        units.push_back(std::move(clone));
    }
}

Field::Field(Field&& other) noexcept
    : width(other.width), height(other.height), max_units(other.max_units), units(std::move(other.units)) {
    other.width = 0;
    other.height = 0;
    other.max_units = 0;
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        units.clear();
        width = other.width;
        height = other.height;
        max_units = other.max_units;
        for (const auto& u : other.units) {
            auto clone = u->clone();
            clone->setPosition(u->getX(), u->getY());
            units.push_back(std::move(clone));
        }
    }
    return *this;
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other) {
        units = std::move(other.units);
        width = other.width;
        height = other.height;
        max_units = other.max_units;
        other.width = 0;
        other.height = 0;
        other.max_units = 0;
    }
    return *this;
}

bool Field::addUnit(std::unique_ptr<Unit> unit, int x, int y) {
    if (isFull()) return false;
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    if (getUnitAt(x, y)) return false;  // занято
    unit->setPosition(x, y);
    units.push_back(std::move(unit));
    return true;
}

std::unique_ptr<Unit> Field::removeUnit(int x, int y) {
    auto it = std::find_if(units.begin(), units.end(),
        [x, y](const auto& u) { return u->getX() == x && u->getY() == y; });
    if (it != units.end()) {
        auto removed = std::move(*it);
        units.erase(it);
        removed->setPosition(-1, -1);  // снять с поля
        return removed;
    }
    return nullptr;
}

std::optional<Unit*> Field::getUnitAt(int x, int y) const {
    for (const auto& u : units) {
        if (u->getX() == x && u->getY() == y) return u.get();
    }
    return std::nullopt;
}

std::string Field::toString() const {
    std::string s = "Field " + std::to_string(width) + "x" + std::to_string(height) + " (" +
        std::to_string(units.size()) + "/" + std::to_string(max_units) + " units)\n";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto unit_opt = getUnitAt(x, y);
            if (unit_opt) {
                char c = (*unit_opt)->getType()[0];  // первая буква типа
                s += c;
            }
            else {
                s += '.';
            }
            s += ' ';
        }
        s += '\n';
    }
    return s;
}