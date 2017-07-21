#include "potion.h"

Potion::Potion(int x, int y, Grid *grid): Item{x, y, grid} {}

char Potion::getChar() {
  return 'P';
}
