#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H
#include "potion.h"

class PoisonHealth: public Potion {
public:
  PoisonHealth(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter *pc) override;
  bool consumedBy(Drow *drow) override;
  std::string getType() override;
};
#endif
