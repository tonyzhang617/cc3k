#include "orcs.h"
using namespace std;

Orcs::Orcs(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 180;
  atk = 30;
  def = 25;
}

void Orcs::attack(Character *c) {
  bool success = rand() % 2;
  if (success) {
    c->attackedBy(this);
  }
}
