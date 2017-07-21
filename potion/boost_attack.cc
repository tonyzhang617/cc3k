#include "boost_attack.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

BoostAttack::BoostAttack(int x, int y): Potion{x, y} {}

void BoostAttack::consumedBy(PlayerCharacter * pc) {
  pc->modifyAtk(5);
}

void BoostAttack::consumedBy(Drow *drow) {
  drow->modifyAtk(5*1.5);
}
