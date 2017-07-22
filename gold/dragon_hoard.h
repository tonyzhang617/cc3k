#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H
#include "gold.h"

class Dragon;
class DragonHoard : public Gold{
  Dragon *dragon;
public:
  DragonHoard(int x, int y, Grid *grid, Dragon *dragon);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
};
#endif
