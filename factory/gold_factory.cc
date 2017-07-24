#include "gold_factory.h"
#include "../gold/dragon_hoard.h"
#include "../NPCs/dragon.h"
#include "../gold/normal_hoard.h"
#include "../gold/small_hoard.h"
#include "enemy_factory.h"
using namespace std;

GoldFactory::GoldFactory(Grid *grid): Factory{grid}, gts{GoldType::SMALL_HOARD, GoldType::SMALL_HOARD,
      GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD,
      GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD, GoldType::DRAGON_HOARD} {}

void GoldFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::RANDOM_ENTITY) {
    GoldType gt = gts[rand() % 8];
    createGold(x, y, gt);
  }
}

void GoldFactory::createGold(int x, int y, GoldType gt) {
  if (gt == GoldType::SMALL_HOARD) {
    grid->addNewGold(new SmallHoard(x, y, grid));
  } else if (gt == GoldType::NORMAL_HOARD) {
    grid->addNewGold(new NormalHoard(x, y, grid));
  } else if (gt == GoldType::DRAGON_HOARD) {
    DragonHoard *dh = new DragonHoard(x, y, grid);
    grid->addNewGold(dh);
    int dx = x;
    int dy = y;
    while (1) {
      Direction dir = static_cast<Direction>(rand()%8);
      grid->findDestination(dx, dy, dir);
      CellType ct = grid->getCellTypeAt(dx, dy);
      if (ct==CellType::FLOOR) break;
    }
    grid->addNewEnemy(new Dragon{dx, dy, grid, dh});
  }
}
