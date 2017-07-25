#ifndef POTION_H
#define POTION_H
#include "../item.h"

class Potion: public Item {
public:
  Potion(int x, int y, Grid *grid);
  char getChar() override;
  virtual std::string getType() = 0;
  bool consumedBy(PlayerCharacter *pc) override;
  virtual bool consumedBy(Drow *drow) = 0;
};

#endif
