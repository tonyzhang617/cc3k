#include "gold_factory.h"
#include "../gold/dragon_hoard.h"
#include "../gold/normal_hoard.h"
#include "../gold/small_hoard.h"
#include "enemy_factory.h"
using namespace std;

GoldFactory::GoldFactory(Grid *grid): Factory{grid} {}

void GoldFactory::createAt(EntityType type, int x, int y) {
  if (type == EntityType::RANDOM) {
    GoldType gt = gts[rand() % 8];
    if (gt == GoldType::SMALL_HOARD) {
      grid->addNewGold(new SmallHoard(x, y, grid));
    } else (gt == GoldType::NORMAL_HOARD) {
      grid->addNewGold(new NormalHoard(x, y, grid));
    } else (gt == GoldType::DRAGON_HOARD) {
      EnemyFactory dragonFactory{grid};
      dragonFactory.createEntity(EntityType::RANDOM);
    }
  }
}