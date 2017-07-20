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