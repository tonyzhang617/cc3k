#include "poison_health.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

PoisonHealth::PoisonHealth(int x, int y): Potion{x, y} {}

void PoisonHealth::consumedBy(PlayerCharacter * pc) {
  pc->modifyHP(-10);
}

void PoisonHealth::consumedBy(Drow * drow) {
  drow->modifyHP(-10*1.5);
}
