#include "enemy_factory.h"
#include "../NPCs/dragon.h"
#include "../NPCs/dwarf.h"
#include "../NPCs/elf.h"
#include "../NPCs/halfling.h"
#include "../NPCs/human.h"
#include "../NPCs/merchant.h"
#include "../NPCs/orcs.h"
#include "../gold/dragon_hoard.h"

using namespace std;

EnemyFactory::EnemyFactory(Grid *grid): Factory{grid}, ets{EnemyType::HUMAN, EnemyType::HUMAN, EnemyType::HUMAN, EnemyType::HUMAN,
                                                            EnemyType::DWARF, EnemyType::DWARF, EnemyType::DWARF,
                                                            EnemyType::HALFLING, EnemyType::HALFLING, EnemyType::HALFLING,
                                                            EnemyType::HALFLING, EnemyType::HALFLING,
                                                            EnemyType::ELF, EnemyType::ELF, EnemyType::ORCS, EnemyType::ORCS,
                                                            EnemyType::MERCHANT, EnemyType::MERCHANT} {}

void EnemyFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::RANDOM_ENTITY) {
    EnemyType et = ets[rand() % 18];
    if (et == EnemyType::DRAGON) {
      Dragon *dragon = new Dragon{x, y, grid};
      grid->addNewEnemy(dragon);
      // Spawn DragonHoard accordingly
      int destx = x;
      int desty = y;
      while (1) {
        Direction dir = static_cast<Direction>(rand()%8);
        grid->findDestination(destx, desty, dir);
        CellType ct = grid->getCellTypeAt(destx, desty);
        if (ct==CellType::FLOOR) break;
      }
      grid->addNewGold(new DragonHoard(x, y, grid, dragon));
    } else if (et == EnemyType::DWARF) {
      grid->addNewEnemy(new Dwarf(x, y, grid));
    } else if (et == EnemyType::ELF) {
      grid->addNewEnemy(new Elf(x, y, grid));
    } else if (et == EnemyType::HALFLING) {
      grid->addNewEnemy(new Halfling(x, y, grid));
    } else if (et == EnemyType::HUMAN) {
      grid->addNewEnemy(new Human(x, y, grid));
    } else if (et == EnemyType::MERCHANT) {
      grid->addNewEnemy(new Merchant(x, y, grid));
    } else if (et == EnemyType::ORCS) {
      grid->addNewEnemy(new Orcs(x, y, grid));
    }
  }
}



