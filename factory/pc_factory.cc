#include "pc_factory.h"
#include "../PCs/drow.h"
#include "../PCs/goblin.h"
#include "../PCs/shade.h"
#include "../PCs/troll.h"
#include "../PCs/vampire.h"
using namespace std;

PCFactory::PCFactory(Grid *grid): Factory{grid} {}

void PCFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::DROW) {
    grid->setPlayerCharacter(shared_ptr<PlayerCharacter>(new Drow(x, y, grid)));
  } else if (type == EntityType::GOBLIN) {
    grid->setPlayerCharacter(shared_ptr<PlayerCharacter>(new Goblin(x, y, grid)));
  } else if (type == EntityType::SHADE) {
    grid->setPlayerCharacter(shared_ptr<PlayerCharacter>(new Shade(x, y, grid)));
  } else if (type == EntityType::TROLL) {
    grid->setPlayerCharacter(shared_ptr<PlayerCharacter>(new Troll(x, y, grid)));
  } else if (type == EntityType::VAMPIRE) {
    grid->setPlayerCharacter(shared_ptr<PlayerCharacter>(new Vampire(x, y, grid)));
  }
}

