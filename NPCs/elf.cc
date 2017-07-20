#include "elf.h"
using namespace std;

Elf::Elf(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 140;
  atk = 30;
  def = 10;
}

void Elf::attack(Character *c) {
  c->attackedBy(this);
}
