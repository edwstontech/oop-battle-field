#ifndef CAVALRY_H
#define CAVALRY_H

#include "Unit.h"

class Horseman : public Unit {
public:
    Horseman();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 4; }   // конница — мобильная
};

class Knight : public Unit {
public:
    Knight();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 3; }   // рыцари в латах — чуть медленнее, но прочнее
};

#endif