#ifndef BOOST_ATTACK_H
#define BOOST_ATTACK_H
#include "potion.h"

class BoostAttack: public Potion {
public:
  BoostAttack(int x, int y, Grid *grid);
  void consumedBy(PlayerCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};

#endif
