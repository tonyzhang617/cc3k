#include "goblin.h"
using namespace std;

Goblin::Goblin(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 110, 15, 20) {}

void Goblin::slay(Character *c) {
  c->slainBy(this);
  addGold(5);
}

void Goblin::attackedBy(Orcs *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  damage *= 1.5;
  modifyHP(-damage);
}
