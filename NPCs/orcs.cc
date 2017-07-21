#include "orcs.h"
#include "../grid.h"
using namespace std;

Orcs::Orcs(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 180;
  atk = 30;
  def = 25;
}

bool Orcs::attack(Character *c) {
  bool success = rand() % 2;
  if (success) {
    c->attackedBy(this);
    return true;
  } else {
    // grid->addAction("Orcs attacked you but missed. ");
    return false;
  }
}

char Orcs::getChar() {
  return 'O';
}
