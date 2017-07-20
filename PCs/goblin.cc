#include "goblin.h"
using namespace std;

Goblin::Goblin(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 110, 15, 20) {}

void Goblin::slay(Character *c) {
  c->slainBy(this);
  addGold(5);
}

void Goblin::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
  hp = min(defaultHP, hp);
}

void Goblin::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void Goblin::modifyDef(int n) {
  def = max(0, def+n);
}

// TODO

//void Goblin::attackedBy(Orcs *c) {
//  double damage = ceil((100 / (100 + def))*(c->get));
//  damage *= 1.5;
//  modifyHP(-damage);
//}
