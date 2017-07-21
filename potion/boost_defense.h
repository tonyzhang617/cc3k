#ifndef BOOST_DEFENSE_H
#define BOOST_DEFENSE_H
#include "potion.h"

class BoostDefense: public Potion {
public:
  BoostDefense::BoostDefense(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};

#endif
