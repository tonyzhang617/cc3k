#ifndef WOUND_ATTACK_H
#define WOUND_ATTACK_H
#include "potion.h"

class WoundAttack: public Potion {
public:
  WoundAttack(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  std::string getType() override;
};
#endif
