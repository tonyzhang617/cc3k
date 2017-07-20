#include "troll.h"
using namespace std;

Troll::Troll(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 125, 25, 25) {}

void Troll::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
  hp = min(defaultHP, hp);
}

void Troll::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void Troll::modifyDef(int n) {
  def = max(0, def+n);
}

void Troll::attack(Character *c) {
  c->attackedBy(this);
  modifyHP(5);
}

void Troll::trollMove() {
  modifyHP(5);
}

// TODO

//void Troll::consumePotion(Item *p) {
//  p->consumedBy(this);
//  modifyHP(5);
//}
