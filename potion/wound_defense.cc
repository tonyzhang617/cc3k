#include "wound_defense.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

WoundDefense::WoundDefense(int x, int y, Grid *grid): Potion{x, y, grid} {}

void WoundDefense::consumedBy(PlayerCharacter * pc) {
  pc->modifyDef(-5);
}

void WoundDefense::consumedBy(Drow *drow) {
  drow->modifyDef(-5*1.5);
}
