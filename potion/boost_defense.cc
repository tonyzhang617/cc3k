#include "boost_defense.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

BoostDefense::BoostDefense(int x, int y, Grid *grid): Potion{x, y, grid} {}

bool BoostDefense::consumedBy(PlayerCharacter * pc) {
  pc->modifyDef(5);
  return true;
}

bool BoostDefense::consumedBy(Drow * drow) {
  drow->modifyDef(5*1.5);
  return true;
}

string BoostDefense::getType() {
  return "Boost Defense";
}
