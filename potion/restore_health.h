#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H
#include "potion.h"

class RestoreHealth: public Potion {
public:
  RestoreHealth::RestoreHealth(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};
#endif
