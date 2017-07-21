#include "elf.h"
using namespace std;

Elf::Elf(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 140;
  atk = 30;
  def = 10;
}

bool Elf::attack(Character *c) {
  return c->attackedBy(this);
}

char Elf::getChar() {
  return 'E';
}

string Elf::getRace() {
  return "elf";
}
