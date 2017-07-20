#include "player_character.h"
#include "../grid.h"
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

void PlayerCharacter::attack(Character *c) {
  c->attackedBy(this);
}

void PlayerCharacter::consumePotion(Item *p) {
  // p->consumedBy(this);
  // TODO
}

void PlayerCharacter::resetAtkDef() {
  atk = defaultAtk;
  def = defaultDef;
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
      x = destx;
      y = desty;
      cout << "Character moved." << endl;
      trollMove();
      break;
    default:
      cout << "Invalid move." << endl;
  }
}

void PlayerCharacter::trollMove() {}
