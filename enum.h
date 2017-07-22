#ifndef ENUM_H
#define ENUM_H

#include <string>

enum CellType {PC, ENEMY, POTION, GOLD, WALL, DOORWAY, PASSAGE, FLOOR, ABYSS, STAIR};
enum Direction {SO, NO, EA, WE, SW, SE, NW, NE, RANDOM};
enum EntityType {DROW, GOBLIN, SHADE, TROLL, VAMPIRE, RANDOM_ENTITY};
enum EnemyType {DRAGON, DWARF, ELF, HALFLING, HUMAN, MERCHANT, ORCS};
enum PotionType {BOOST_ATTACK, BOOST_DEFENSE, POISON_HEALTH, RESTORE_HEALTH, WOUND_ATTACK, WOUND_DEFENSE};
enum GoldType {DRAGON_HOARD, MERCHANT_HOARD, NORMAL_HOARD, SMALL_HOARD};

Direction getDirFromString(std::string s);
EntityType getEntityFromString(std::string s);

#endif
