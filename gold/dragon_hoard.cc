#include "dragon_hoard.h"
#include "../NPCs/dragon.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

DragonHoard::DragonHoard(int x, int y, Grid *grid, Dragon *dragon):
    Gold{x, y, grid, 6}, dragon{dragon} {
  dragon->setHoard(this);
}

bool DragonHoard::consumedBy(PlayerCharacter * pc) {
  if (dragon->isDead()) {
    pc->addGold(value);
    isUsed = true;
    return true;
  }
  return false;
}

bool DragonHoard::consumedBy(Drow * drow) {
  if (dragon->isDead()) {
    drow->addGold(value);
    isUsed = true;
    return true;
  }
  return false;
}
