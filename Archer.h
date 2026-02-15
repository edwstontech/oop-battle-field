#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

class Archer : public Unit {
public:
    Archer();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 2; }   // лучники обычно медленнее конницы
};

class Crossbowman : public Unit {
public:
    Crossbowman();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 1; }   // арбалетчики ещё тяжелее/медленнее
};

#endif