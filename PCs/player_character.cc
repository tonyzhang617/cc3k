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
  trollMove();
  string s = "Enemy has " + to_string(c->getHp()) + " HP left. ";
  grid->addAction(s);
}

void PlayerCharacter::consumePotion(Item *p) {
  // p->consumedBy(this);
  // trollMove();
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
  atk += max(0, atk+n);
}

void PlayerCharacter::modifyDef(int n) {
  def += max(0, atk+n);
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
      cout << "Character moved. " << endl;
      trollMove();
      break;
    default:
      cout << "Invalid move. " << endl;
  }
}

void PlayerCharacter::trollMove() {}
