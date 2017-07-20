#include "halfling.h"
#include "../grid.h"
using namespace std;

Halfling::Halfling(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 100;
  atk = 15;
  def = 20;
}

void Halfling::attackedBy(Character *c) {
  bool success = rand() % 2;
  if (success) {
    int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    grid->addAction("You attacked Halfling. ");
  } else {
    grid->addAction("You attacked Halfling but missed. ");
  }
  if (isDead()) {
    c->slay(this);
  }
}

void Halfling::attackedBy(Vampire *c) {
  bool success = rand() % 2;
  if (success) {
    int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
    modifyHP(-damage);
    c->modifyHP(5);
    grid->addAction("You attacked Halfling. ");
  } else {
    grid->addAction("You attacked Halfling but missed. ");
  }
  if (isDead()) {
    c->slay(this);
  }
}

char Halfling::getChar() {
  return 'L';
}
