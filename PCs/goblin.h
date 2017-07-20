#ifndef GOBLIN_H
#define GOBLIN_H
#include "player_character.h"

class Goblin : public PlayerCharacter {
public:
  Goblin(int x, int y, Grid *grid);
  void slay(Character *c) override;
  void modifyHP(int n) override;
  void modifyAtk(int n) override;
  void modifyDef(int n) override;
  // void resetAtkDef() override;
  // void attackedBy(Orcs *c) override;
};

#endif
