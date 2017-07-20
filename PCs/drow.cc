#include "drow.h"
using namespace std;

Drow::Drow(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 150, 25, 15) {}

void Drow::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
  hp = min(defaultHP, hp);
}

void Drow::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void Drow::modifyDef(int n) {
  def = max(0, def+n);
}

void Drow::consumePotion(Item *p) {
  // TODO
  // p->consumedBy(this);
}

//void Drow::attackedBy(Elf *e) {
//  double damage = ceil((100 / (100 + def))*(e->getAtk()));
//  modifyHP(-damage);
//}
