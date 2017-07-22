#ifndef WOUND_DEFENSE_H
#define WOUND_ATTACK_H
#include "potion.h"

class WoundDefense: public Potion {
public:
  WoundDefense(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  std::string getType() override;
};
#endif
