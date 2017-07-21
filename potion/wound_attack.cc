#include "wound_attack.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

WoundAttack::WoundAttack(int x, int y): Potion{x, y} {}

void WoundAttack::consumedBy(PlayerCharacter * pc) {
  pc->modifyAtk(-5);
}

void WoundAttack::consumedBy(Drow *drow) {
  drow->modifyAtk(-5*1.5);
}
