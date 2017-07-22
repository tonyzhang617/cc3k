#ifndef BOOST_DEFENSE_H
#define BOOST_DEFENSE_H
#include "potion.h"

class BoostDefense: public Potion {
public:
  BoostDefense(int x, int y, Grid *grid);
  bool consumedBy(PlayerCharacter * pc) override;
  bool consumedBy(Drow * drow) override;
  std::string getType() override;
};

#endif
