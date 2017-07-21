#include "potion.h"

Potion::Potion(int x, int y): Item{x, y} {}

char Potion::getChar() {
  return 'P';
}
