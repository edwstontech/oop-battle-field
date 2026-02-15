# oop-battle-field
Используются принципы ООП: наследование, полиморфизм, инкапсуляция. Ключевые паттерны: Factory Method для создания юнитов, Iterator для обхода поля. Поддержка копирования/перемещения для эффективности.

Требования и реализация

Класс игрового поля (Field): Прямоугольная сетка (width x height), лимит юнитов, add/remove, copy/move. Использует vector<unique_ptr<Unit>> для владения.
Классы юнитов: Базовый Unit с интерфейсом (move, clone). 3 типа: Infantry (Swordsman, Spearman), Archer (Archer, Crossbowman), Cavalry (Horseman, Knight). Атрибуты в отдельных классах (Health, etc.).
Фабрика: BasicUnitFactory создаёт юниты по enum.
Итератор: Forward iterator по юнитам на поле.
Оптимизация: Параметры по move/reference, unique_ptr для избежания копий.
Демонстрации: В main.cpp 5 примеров (add, move, iterate, copy, remove).

Field after adding units:
Field 10x5 (4/10 units)
. . . . . . . . . . 
. S . . . . . . . . 
. . S . . . . . . . 
. . . A . . . . . . 
. . . . K . . . . . 

Moved Swordsman to (1,3): success
Field after move:
Field 10x5 (4/10 units)
. . . . . . . . . . 
. . . . . . . . . . 
. . S . . . . . . . 
. S . A . . . . . . 
. . . . K . . . . . 

Iterating over units:
Spearman at (2,2) HP: 100/100 Attack: 22 Armor: 4
Archer at (3,3) HP: 80/80 Attack: 15 Armor: 2
Knight at (4,4) HP: 140/140 Attack: 24 Armor: 10
Swordsman at (1,3) HP: 120/120 Attack: 18 Armor: 6

Copied field:
Field 10x5 (4/10 units)
. . . . . . . . . . 
. . . . . . . . . . 
. . S . . . . . . . 
. S . A . . . . . . 
. . . . K . . . . . 

Removed unit: Spearman at (-1,-1) HP: 100/100 Attack: 22 Armor: 4
Field after removal:
Field 10x5 (3/10 units)
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. S . A . . . . . . 
. . . . K . . . . . 
