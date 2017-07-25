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
public:
  Item(int x, int y, Grid *grid);
  std::pair<int, int> getPosition();
  virtual char getChar() = 0;
  virtual bool consumedBy(PlayerCharacter *pc) = 0;
};


#endif
