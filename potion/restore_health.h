#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H
#include "potion.h"

class RestoreHealth: public Potion {
public:
  RestoreHealth(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  std::string getType() override;
};
#endif
