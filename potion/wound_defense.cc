#include "wound_defense.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

WoundDefense::WoundDefense(int x, int y, Grid *grid): Potion{x, y, grid} {}

bool WoundDefense::consumedBy(PlayerCharacter * pc) {
  pc->modifyDef(-5);
  return true;
}

bool WoundDefense::consumedBy(Drow *drow) {
  drow->modifyDef(-5*1.5);
  return true;
}

string WoundDefense::getType() {
  return "Wound Defense";
}