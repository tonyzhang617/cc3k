#include "boost_defense.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

BoostDefense::BoostDefense(int x, int y): Potion{x, y} {}

void BoostDefense::consumedBy(PlayerCharacter * pc) {
  pc->modifyDef(5);
}

void BoostDefense::consumedBy(Drow * drow) {
  drow->modifyDef(5*1.5);
}
