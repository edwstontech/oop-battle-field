#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

class Swordsman : public Unit {
public:
    Swordsman();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 2; }
};

class Spearman : public Unit {
public:
    Spearman();
    std::unique_ptr<Unit> clone() const override;
    int moveRange() const override { return 2; }
};

#endif