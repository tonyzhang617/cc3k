#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H
#include "gold.h"

class Dragon;
class DragonHoard : public Gold{
  Dragon *dragon = nullptr;
  bool isGuarded = true;
public:
  DragonHoard(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  void setDragon(Dragon *dragon);
  void freeHoard();
};
#endif
