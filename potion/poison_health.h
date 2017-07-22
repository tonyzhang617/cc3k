#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H
#include "potion.h"

class PoisonHealth: public Potion {
public:
  PoisonHealth(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};
#endif
