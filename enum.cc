#include "enum.h"


Direction getDirFromString(std::string s) {

  if (s == "no") {
    return Direction::NO;
  } else if (s == "no") {
    return Direction::NO;
  } else if (s == "so") {
    return Direction::SO;
  } else if (s == "ea") {
    return Direction::EA;
  } else if (s == "we") {
    return Direction::WE;
  } else if (s == "ne") {
    return Direction::NE;
  } else if (s == "nw") {
    return Direction::NW;
  } else if (s == "se") {
    return Direction::SE;
  } else if (s == "sw") {
    return Direction::SW;
  }

  return Direction::RANDOM;
}


EntityType getEntityFromString(std::string s) {
  if (s == "drow") {
    return EntityType::DROW;
  } else if (s == "goblin") {
    return EntityType::GOBLIN;
  } else if (s == "shade") {
    return EntityType::SHADE;
  } else if (s == "troll") {
    return EntityType::TROLL;
  } else if (s == "vampire") {
    return EntityType::VAMPIRE;
  }

  return EntityType::SHADE;
}

PotionType getPotionFromInt(int n) {
  switch (n) {
    case 0:
      return PotionType::RESTORE_HEALTH;
    case 1:
      return PotionType::BOOST_ATTACK;
    case 2:
      return PotionType::BOOST_DEFENSE;
    case 3:
      return PotionType::POISON_HEALTH;
    case 4:
      return PotionType::WOUND_ATTACK;
    default:
      return PotionType::WOUND_DEFENSE;
  }
}

GoldType getGoldFromInt(int n) {
  switch (n) {
    case 6:
      return GoldType::NORMAL_HOARD;
    case 7:
      return GoldType::SMALL_HOARD;
    case 8:
      return GoldType::MERCHANT_HOARD;
    default:
      return GoldType::DRAGON_HOARD;
  }
}
