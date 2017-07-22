#include "gold_factory.h"
#include "../gold/dragon_hoard.h"
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
    if (gt == GoldType::SMALL_HOARD) {
      grid->addNewGold(new SmallHoard(x, y, grid));
    } else if (gt == GoldType::NORMAL_HOARD) {
      grid->addNewGold(new NormalHoard(x, y, grid));
    } else if (gt == GoldType::DRAGON_HOARD) {
      EnemyFactory dragonFactory{grid};
      dragonFactory.createEntity(EntityType::RANDOM_ENTITY);
    }
  }
}