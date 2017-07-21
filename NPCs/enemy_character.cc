#include "enemy_character.h"
#include "../grid.h"
#include "../subject.h"
using namespace std;

EnemyCharacter::EnemyCharacter(int x, int y, Grid *g): Character(x, y, g) {}

void EnemyCharacter::makeMove(Direction dir) {
  if (dir == Direction::RANDOM) {
    while (1) {
      dir = static_cast<Direction>(rand() % 8);
      int destx = x;
      int desty = y;
      grid->findDestination(destx, desty, dir);

      CellType ct = grid->getCellTypeAt(destx, desty);
      if (ct == CellType::FLOOR) {
          x = destx;
          y = desty;
          break;
      }
    }
  }
}

bool EnemyCharacter::attack(Character *c) {
  bool success = rand() % 2;
  if (success) {
    c->attackedBy(this);
    return true;
  } else {
    return false;
  }
}

bool EnemyCharacter::attackedBy(Character *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  if (isDead()) {
    c->slay(this);
  }
  return true;
}

void EnemyCharacter::modifyHP(int n) {
  if (n < 0) {
    hp = max(0, hp+n);
  }
}

char EnemyCharacter::getChar() {
  return '&';
}

string EnemyCharacter::getRace() {
  return "enemy";
}
