#include "player_character.h"
#include "../grid.h"
#include "../potion/potion.h"
using namespace std;

PlayerCharacter::PlayerCharacter(int x, int y, Grid *g, int dHP, int dAtk, int dDef):
    Character(x, y, g), defaultHP{dHP}, defaultAtk{dAtk}, defaultDef{dDef} {
  atk = dAtk;
  hp = dHP;
  def = dDef;
}

char PlayerCharacter::getChar() {
  return '@';
}

bool PlayerCharacter::attack(Character *c) {
  if (c->attackedBy(this)) {
    trollMove();
    return true;
  }
  return false;
}

void PlayerCharacter::consumePotion(Potion *p) {
  p->consumedBy(this);
  trollMove();
}

void PlayerCharacter::resetAtkDef() {
  atk = defaultAtk;
  def = defaultDef;
}

void PlayerCharacter::modifyHP(int n) {
  hp += n;
  hp = max(0, hp);
  hp = min(defaultHP, hp);
}

void PlayerCharacter::modifyAtk(int n) {
  atk = max(0, atk+n);
}

void PlayerCharacter::modifyDef(int n) {
  def = max(0, def+n);
}

void PlayerCharacter::makeMove(Direction dir) {
  int destx = x;
  int desty = y;
  grid->findDestination(destx, desty, dir);

  CellType ct = grid->getCellTypeAt(destx, desty);
  switch (ct) {
    case CellType::GOLD:
    case CellType::DOORWAY:
    case CellType::PASSAGE:
    case CellType::FLOOR:
    case CellType::STAIR:
      x = destx;
      y = desty;
      trollMove();
      break;
    default:
      grid->addAction("Invalid move. ");
      break;
  }
}

void PlayerCharacter::trollMove() {}

void PlayerCharacter::setPosition(int newX, int newY) {
  x = newX;
  y = newY;
}

int PlayerCharacter::getScore() {
  return gold;
}