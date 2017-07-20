#include "merchant.h"
using namespace std;

Merchant::Merchant(int x, int y, Grid *grid): EnemyCharacter(30, 70, grid) {
  hp = 30;
  atk = 70;
  def = 5;
}

void Merchant::slainBy(Character *c) {
  c->addGold(legacy);
  isHostile = true;
}

void Merchant::attackedBy(Character *c) {
  double damage = ceil((100 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  isHostile = true;
}

void Merchant::attackedBy(Vampire *c) {
  double damage = ceil((100 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  c->modifyHP(5);
  isHostile = true;
}
