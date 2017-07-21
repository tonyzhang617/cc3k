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
  bool attackedBy(Character *c) override;
  bool attackedBy(Vampire *c) override;
  char getChar() override;
  void notify(Subject *whoNotified) override;
  std::string getRace() override;
};

#endif
