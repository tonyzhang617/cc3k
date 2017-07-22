#ifndef BOOST_ATTACK_H
#define BOOST_ATTACK_H
#include "potion.h"

class BoostAttack: public Potion {
public:
  BoostAttack(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  std::string getType() override;
};

#endif
