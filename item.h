#ifndef ITEM_H
#define ITEM_H
#include <utility>

class PlayerCharacter;
class Drow;
class Item{
  int x;
  int y;
public:
  Item(int x, int y);
  std::pair<int, int> getPosition();
  virtual char getChar() = 0;
  virtual void consumedBy(PlayerCharacter * pc) = 0;
  virtual void consumedBy(Drow * drow) = 0;
};


#endif
