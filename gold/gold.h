#ifndef GOLD_H
#define GOLD_H
#include "../item.h"

class Gold: public Item {
protected:
  int value = 0;
public:
  Gold(int x, int y, Grid *grid, int value);
  char getChar() override;
  bool consumedBy(PlayerCharacter *pc) override;
};

#endif
