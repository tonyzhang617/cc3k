#ifndef POTION_H
#define POTION_H
#include "../item.h"

class Potion: public Item {
public:
  Potion(int x, int y);
  char getChar() override;
};

#endif
