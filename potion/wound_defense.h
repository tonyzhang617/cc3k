#ifndef WOUND_DEFENSE_H
#define WOUND_ATTACK_H
#include "potion.h"

class WoundDefense: public Potion {
public:
  WoundDefense::WoundDefense(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};
#endif
