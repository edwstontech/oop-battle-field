#include "Field.h"
#include "UnitFactory.h"
#include <iostream>
#include <memory>

int main() {
    // Создание поля
    Field field(10, 5, 10);  // 10x5, max 10 юнитов

    BasicUnitFactory factory;

    // Демонстрация 1: Добавление юнитов
    auto u1 = factory.createUnit(UnitType::Swordsman);
    auto u2 = factory.createUnit(UnitType::Spearman);
    auto u3 = factory.createUnit(UnitType::Archer);
    auto u4 = factory.createUnit(UnitType::Knight);

    field.addUnit(std::move(u1), 1, 1);
    field.addUnit(std::move(u2), 2, 2);
    field.addUnit(std::move(u3), 3, 3);
    field.addUnit(std::move(u4), 4, 4);

    std::cout << "Поле после добавления единиц:\n" << field.toString() << "\n";

    // Демонстрация 2: Перемещение юнита
    auto unit_at_1_1 = field.getUnitAt(1, 1);
    if (unit_at_1_1) {
        bool moved = (*unit_at_1_1)->moveTo(1, 3, field);
        std::cout << "Переместил Мечника на (1,3): " << (moved ? "Успешно" : "Неудачно") << "\n";
    }
    std::cout << "Поле после хода:\n" << field.toString() << "\n";

    // Демонстрация 3: Итератор и информация о юнитах
    std::cout << "Итерация по единицам:\n";
    for (auto* unit : field) {
        if (unit) std::cout << unit->getInfo() << "\n";
    }

    // Демонстрация 4: Копирование поля
    Field field_copy = field;
    std::cout << "Скопированное поле:\n" << field_copy.toString() << "\n";

    // Демонстрация 5: Удаление юнита
    auto removed = field.removeUnit(2, 2);
    if (removed) {
        std::cout << "Удаленная единица: " << removed->getInfo() << "\n";
    }
    std::cout << "Поле после удаления:\n" << field.toString() << "\n";

    return 0;
}