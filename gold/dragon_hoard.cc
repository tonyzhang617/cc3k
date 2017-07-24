#include "dragon_hoard.h"
#include "../NPCs/dragon.h"
#include "../PCs/player_character.h"
#include "../PCs/drow.h"
using namespace std;

DragonHoard::DragonHoard(int x, int y, Grid *grid): Gold{x, y, grid, 6} {
}

bool DragonHoard::consumedBy(PlayerCharacter * pc) {
  if (!isGuarded) {
    pc->addGold(value);
    isUsed = true;
    return true;
  }
  return false;
}

bool DragonHoard::consumedBy(Drow * drow) {
  if (!isGuarded) {
    drow->addGold(value);
    isUsed = true;
    return true;
  }
  return false;
}

void DragonHoard::setDragon(Dragon *d) {
  dragon = d;
}

void DragonHoard::freeHoard() {
  isGuarded = false;
}
