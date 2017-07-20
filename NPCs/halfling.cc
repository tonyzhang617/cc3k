#include "halfling.h"
using namespace std;

Halfling::Halfling(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 100;
  atk = 15;
  def = 20;
}

void Halfling::attackedBy(Character *c) {
  bool success = rand() % 2;
  if (success) {
    double damage = ceil((100 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
  }
  if (isDead()) {
    slainBy(c);
  }
}

void Halfling::attackedBy(Vampire *c) {
  bool success = rand() % 2;
  if (success) {
    double damage = ceil((100 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    c->modifyHP(5);
  }
  if (isDead()) {
    slainBy(c);
  }
}
