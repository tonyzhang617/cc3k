#include "restore_health.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

RestoreHealth::RestoreHealth(int x, int y, Grid *grid): Potion{x, y, grid} {}

bool RestoreHealth::consumedBy(PlayerCharacter * pc) {
  pc->modifyHP(10);
  isUsed = true;
  return true;
}

bool RestoreHealth::consumedBy(Drow *drow) {
  drow->modifyHP(10*1.5);
  isUsed = true;
  return true;
}

string RestoreHealth::getType() {
  return "Restore Health";
}