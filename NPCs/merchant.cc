#include "merchant.h"
#include "../grid.h"
using namespace std;

bool Merchant::isHostile = false;

Merchant::Merchant(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 30;
  atk = 70;
  def = 5;
}

void Merchant::slainBy(Character *c) {
  c->addGold(legacy);
  isHostile = true;
}

bool Merchant::attackedBy(Character *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  isHostile = true;
  if (isDead()) {
    c->slay(this);
  }
  return true;
}

bool Merchant::attackedBy(Vampire *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  c->modifyHP(5);
  isHostile = true;
  if (isDead()) {
    c->slay(this);
  }
  return true;
}

char Merchant::getChar() {
  return 'M';
}

void Merchant::notify(Subject *whoNotified) {
  if (!isDead()) {
    int subx = whoNotified->getPosition().first;
    int suby = whoNotified->getPosition().second;
    if (abs(subx - x) <= 1 && abs(suby - y) <= 1 && !(subx == x && suby == y) && isHostile) {
      grid->enemyAttack(this);
    } else {
      makeMove();
    }
  }
}

string Merchant::getRace() override {
  return "merchant";
}
