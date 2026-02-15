#ifndef FIELD_H
#define FIELD_H

#include "Unit.h"
#include <vector>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

class Field {
private:
    int width;
    int height;
    size_t max_units;
    std::vector<std::unique_ptr<Unit>> units;

public:
    Field(int w, int h, size_t max = 50);
    Field(const Field& other);
    Field(Field&& other) noexcept;
    Field& operator=(const Field& other);
    Field& operator=(Field&& other) noexcept;

    bool addUnit(std::unique_ptr<Unit> unit, int x, int y);
    std::unique_ptr<Unit> removeUnit(int x, int y);

    std::optional<Unit*> getUnitAt(int x, int y) const;

    size_t count() const { return units.size(); }
    bool isFull() const { return units.size() >= max_units; }

    int getWidth()  const { return width; }
    int getHeight() const { return height; }

    // Итератор
    class Iterator {
    private:
        const Field* field;
        size_t index = 0;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Unit*;
        using difference_type = std::ptrdiff_t;
        using pointer = Unit**;
        using reference = Unit*&;

        Iterator(const Field* f, size_t i) : field(f), index(i) {}

        Unit* operator*() const {
            if (index >= field->units.size()) return nullptr;
            return field->units[index].get();
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index || field != other.field;
        }
    };

    Iterator begin() const { return Iterator(this, 0); }
    Iterator end()   const { return Iterator(this, units.size()); }

    std::string toString() const;
};

#endif