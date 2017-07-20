#include "dwarf.h"
using namespace std;

Dwarf::Dwarf(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 100;
  atk = 20;
  def = 20;
}

void Dwarf::attackedBy(Vampire *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  c->modifyHP(-5);
  if(isDead()) {
    c->slay(this);
  }
}
