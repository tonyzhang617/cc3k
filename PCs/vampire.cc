#include "vampire.h"
using namespace std;

Vampire::Vampire(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 50, 25, 25) {}

void Vampire::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
}

void Vampire::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void Vampire::modifyDef(int n) {
  def = max(0, def+n);
}
