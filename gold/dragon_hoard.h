#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H
#include "gold.h"

class Dragon;
class DragonHoard : public Gold{
  bool isGuarded = true;
public:
  DragonHoard(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  void freeHoard();
};
#endif
