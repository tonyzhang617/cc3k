#ifndef DROW_H
#define DROW_H
#include "player_character.h"
#include "elf.h"

class Item;
class Drow : public PlayerCharacter {
public:
  Drow(int x, int y, Grid *grid);
  void modifyHP(int n) override;
  void modifyAtk(int n) override;
  void modifyDef(int n) override;
  // void resetAtkDef() override;
  void consumePotion(Item *p) override;

  // TODO
  // void attackedBy(Elf *c) override;
};

#endif
