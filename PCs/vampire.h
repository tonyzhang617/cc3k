#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player_character.h"

class Vampire : public PlayerCharacter {
public:
  Vampire(int x, int y, Grid *grid);
  void modifyHP(int n) override;
  void modifyAtk(int n) override;
  void modifyDef(int n) override;
  // void resetAtkDef() override;
};

#endif
