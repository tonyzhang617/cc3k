#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy_character.h"
#include "../character.h"
#include "../PCs/vampire.h"
#include "../grid.h"

class Merchant : public EnemyCharacter {
  static bool isHostile;
  const int legacy = 4;
public:
  Merchant(int x, int y, Grid *grid);
  void slainBy(Character *c) override;
  void attackedBy(Character *c) override;
  void attackedBy(Vampire *c) override;
  char getChar() override;
};

#endif
