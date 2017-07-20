#include "player_character.h"
#include "../grid.h"
using namespace std;

PlayerCharacter::PlayerCharacter(int x, int y, Grid *g, int dHP, int dAtk, int dDef): Character(x, y, grid),
                                                                                      defaultHP{dHP}, defaultAtk{dAtk}, defaultDef{dDef} {
  atk = dAtk;
  hp = dHP;
  def = dDef;
}

void PlayerCharacter::attack(Character *c) {
  c->attackedBy(this);
}

void PlayerCharacter::consumePotion(Item *p) {
  // p->consumedBy(this);
  // TODO
}

void PlayerCharacter::slay(Character *c) {
  c->slainBy(this);
}

void PlayerCharacter::resetAtkDef() {
  atk = defaultAtk;
  def = defaultDef;
}

void PlayerCharacter::makeMove(Direction dir) {
  int destx = this->x;
  int desty = this->y;
  grid->findDestination(destx, desty, dir);

  CellType ct = grid->getCellTypeAt(destx, desty);
  switch (ct) {
    case CellType::GOLD:
    case CellType::DOORWAY:
    case CellType::PASSAGE:
    case CellType::FLOOR:
      this->x = destx;
      this->y = desty;
      cout << "Character moved." << endl;
      trollMove();
      break;
    default:
      cout << "Invalid move." << endl;
  }
}

char PlayerCharacter::getChar() {
  return '@';
}

void PlayerCharacter::trollMove() {}
