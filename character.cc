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

void Character::printStatus() {
  string s = "HP: " + to_string(hp) + "ATK: " + to_string(atk) + "DEF: " + to_string(def) + "\n";
  grid->addAction(s);
}

void Character::attackedBy(Character *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  grid->addAction("An attack happened. ");
}

void Character::attackedBy(Elf *c) {
  for (int i = 0; i < 2; i++) {
    bool success = rand() % 2;
    if (success) {
      int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
      modifyHP(-damage);
      grid->addAction("Elf attacked you. ");
    } else {
      grid->addAction("Elf attacked but missed. ");
    }
  }
}

void Character::attackedBy(Vampire *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  c->modifyHP(5);
  grid->addAction("You attacked successfully.");
}

void Character::attackedBy(Orcs *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  grid->addAction("Orcs attacked you.");
}

void Character::slay(Character *c) {
  c->slainBy(this);
}

void EnemyCharacter::slainBy(Character *c) {
  int legacy = 1 + rand() % 2;
  c->addGold(legacy);
  grid->addAction("You slayed an enemy.");
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
