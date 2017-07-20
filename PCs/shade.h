#ifndef SHADE_H
#define SHADE_H
#include "player_character.h"

class Shade : public PlayerCharacter {
public:
  Shade(int x, int y, Grid *grid);
  void modifyHP(int n) override;
  void modifyAtk(int n) override;
  void modifyDef(int n) override;
  // void resetAtkDef() override;
};

#endif
