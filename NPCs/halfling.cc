#include "halfling.h"
#include "../grid.h"
using namespace std;

Halfling::Halfling(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 100;
  atk = 15;
  def = 20;
}

bool Halfling::attackedBy(Character *c) {
  bool success = rand() % 2;
  if (success) {
    int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    if (isDead()) {
      c->slay(this);
    }
    return true;
  } else {
    return false;
  }
}

bool Halfling::attackedBy(Vampire *c) {
  bool success = rand() % 2;
  if (success) {
    int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    c->modifyHP(5);
    if (isDead()) {
      c->slay(this);
    }
    return true;
  } else {
    return false;
  }
}

char Halfling::getChar() {
  return 'L';
}

string Halfling::getRace() override {
  return "halfling";
}
