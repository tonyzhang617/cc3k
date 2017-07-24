#include "character.h"
#include "grid.h"
#include "NPCs/elf.h"
#include "PCs/vampire.h"
#include "NPCs/halfling.h"
#include "PCs/goblin.h"
#include "NPCs/dwarf.h"
#include "NPCs/orcs.h"
using namespace std;

Character::Character(int x, int y, Grid *g): x{x}, y{y}, grid{g} {}

bool Character::isDead() {
  return (hp <= 0);
}

std::pair<int, int> Character::getPosition() {
  return make_pair(x, y);
}

void Character::addGold(int n) {
  if (n > 0) gold += n;
}

bool Character::attackedBy(Character *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  return true;
}

bool Character::attackedBy(Elf *c) {
  bool result = false;
  for (int i = 0; i < 2; i++) {
    bool success = rand() % 2;
    if (success) {
      int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
      modifyHP(-damage);
      result = true;
    }
  }
  return result;
}

bool Character::attackedBy(Vampire *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  c->modifyHP(5);
  return true;
}

bool Character::attackedBy(Orcs *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  return true;
}

void Character::slay(Character *c) {
  c->slainBy(this);
}

void Character::slainBy(Character *c) {
  int legacy = 1 + rand() % 2;
  c->addGold(legacy);
}

int Character::getHp() const {
  return hp;
}
int Character::getAtk() const {
  return atk;
}
int Character::getDef() const {
  return def;
}

int Character::getGold() const {
  return gold;
}

void Character::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
}

void Character::notify(Subject *whoNotified) {
  if (!isDead()) {
    int subx = whoNotified->getPosition().first;
    int suby = whoNotified->getPosition().second;
    if (abs(subx - x) <= 1 && abs(suby - y) <= 1 && !(subx == x && suby == y)) {
      grid->enemyAttack(this);
    } else if (!isFrozen()){
      makeMove(RANDOM);
    }
  }
}
