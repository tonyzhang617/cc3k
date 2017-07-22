#include "boost_attack.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

BoostAttack::BoostAttack(int x, int y, Grid *grid): Potion{x, y, grid} {}

bool BoostAttack::consumedBy(PlayerCharacter * pc) {
  pc->modifyAtk(5);
  isUsed = true;
  return true;
}

bool BoostAttack::consumedBy(Drow *drow) {
  drow->modifyAtk(5*1.5);
  isUsed = true;
  return true;
}

string BoostAttack::getType() {
  return "Boost Attack";
}