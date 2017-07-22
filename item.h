#ifndef ITEM_H
#define ITEM_H
#include <utility>
#include "enum.h"

class Grid;
class PlayerCharacter;
class Drow;
class Item{
  int x;
  int y;
  Grid *grid;
protected:
  bool isUsed = false;
public:
  Item(int x, int y, Grid *grid);
  std::pair<int, int> getPosition();
  virtual char getChar() = 0;
  virtual void consumedBy(PlayerCharacter * pc) = 0;
  virtual void consumedBy(Drow * drow) = 0;
  bool isConsumed();
};


#endif
