#include "vampire.h"
using namespace std;

Vampire::Vampire(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 50, 25, 25) {}

void Vampire::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
}

void Vampire::attack(Character *c) {
  c->attackedBy(this);
}