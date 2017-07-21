#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H
#include "gold.h"

class Dragon;
class DragonHoard : public Gold{
  Dragon *dragon;
public:
  DragonHoard(int x, int y, Grid *gridDragon *dragon);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};
#endif
