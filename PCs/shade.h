#ifndef SHADE_H
#define SHADE_H
#include "player_character.h"

class Shade : public PlayerCharacter {
public:
  Shade(int x, int y, Grid *grid);
  std::string getRace() override;
  int getScore() override;
};

#endif
