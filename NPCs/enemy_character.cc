#include "enemy_character.h"
#include "../grid.h"
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

void EnemyCharacter::attack(Character *c) {
  bool success = rand() % 2;
  if (success) c->attackedBy(this);
}

void EnemyCharacter::attackedBy(Character *c) {
  int damage = ceil((100.0 / (100 + def))*(c->getAtk()));
  modifyHP(-damage);
  grid->addAction("You attacked an enemy. ");
  if (isDead()) {
    c->slay(this);
  }
}

void EnemyCharacter::modifyHP(int n) {
  if (n < 0) {
    hp = max(0, hp+n);
  }
}

char EnemyCharacter::getChar() {
  return '&';
}
