#include "vampire.h"
#include "../grid.h"
using namespace std;

Vampire::Vampire(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 50, 25, 25) {}

void Vampire::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
}

bool Vampire::attack(Character *c) {
  return (c->attackedBy(this));
}

string Vampire::getRace() {
  return "Vampire";
}
