#ifndef GOLD_H
#define GOLD_h
#include "../item.h"

class Gold: public Item {
protected:
  int value = 0;
public:
  Gold(int x, int y, Grid *grid, int value);
  char getChar() override;
  void consumedBy(PlayCharacter * pc) override;
  void consumedBy(Drow * drow) override;
};

#endif
