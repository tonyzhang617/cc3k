#ifndef TROLL_H
#define TROLL_H
#include "player_character.h"

class Troll : public PlayerCharacter {
  void trollMove() override;
public:
  Troll(int x, int y, Grid *grid);
};

#endif
