#include "shade.h"
using namespace std;

Shade::Shade(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 125, 25, 25) {}

void Shade::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
  hp = min(defaultHP, hp);
}

void Shade::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void Shade::modifyDef(int n) {
  def = max(0, def+n);
}
