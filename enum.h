#ifndef ENUM_H
#define ENUM_H

#include <string>

enum CellType {PC, ENEMY, POTION, GOLD, WALL, DOORWAY, PASSAGE, FLOOR, ABYSS};
enum Direction {SO, NO, EA, WE, SW, SE, NW, NE, RANDOM};

Direction getDirFromString(std::string s);

#endif
