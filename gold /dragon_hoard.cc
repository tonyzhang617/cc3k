#include "dragon_hoard.h"
#include "../NPCs/dragon.h"
using namespace std;

DragonHoard::DragonHoard(int x, int y, Dragon *dragon):
    Gold{x, y, 6}, dragon{dragon} {
  dragon->setHoard(this);
}

void DragonHoard::consumedBy(PlayerCharacter * pc) {
  if (dragon->isDead()) {
    pc->addGold(value);
  }
}

void DragonHoard::consumedBy(Drow * drow) {
  if (dragon->isDead()) {
    drow->addGold(value);
  }
}
