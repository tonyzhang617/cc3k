#ifndef WOUND_ATTACK_H
#define WOUND_ATTACK_H
#include "potion.h"

class WoundAttack: public Potion {
public:
  WoundAttack(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};
#endif
