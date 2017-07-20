#ifndef TROLL_H
#define TROLL_H
#include "player_character.h"

class Troll : public PlayerCharacter {
  void trollMove() override;
public:
  Troll(int x, int y, Grid *grid);
  void modifyHP(int n) override;
  void modifyAtk(int n) override;
  void modifyDef(int n) override;
  // void resetAtkDef() override;
  void attack(Character *c) override;
  void consumePotion(Item *p) override;
};

#endif
