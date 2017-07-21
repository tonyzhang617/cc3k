#include "drow.h"
#include "../grid.h"
using namespace std;

Drow::Drow(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 150, 25, 15) {}

void Drow::consumePotion(Item *p) {
  p->consumedBy(this);
}

bool Drow::attackedBy(Elf *c) {
  bool success = rand() % 2;
  if (success) {
    int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    return true;
  } else {
    return false;
  }
}
