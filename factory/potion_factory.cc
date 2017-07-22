#include "potion_factory.h"
#include "../potion/boost_attack.h"
#include "../potion/boost_defense.h"
#include "../potion/poison_health.h"
#include "../potion/restore_health.h"
#include "../potion/wound_attack.h"
#include "../potion/wound_defense.h"

using namespace std;

PotionFactory::PotionFactory(Grid *grid): Factory{grid} {}

void PotionFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::RANDOM_ENTITY) {
    PotionType pt = static_cast<PotionType>(rand()%6);
    if (pt==PotionType::BOOST_ATTACK) {
      grid->addNewPotion(new BoostAttack(x, y, grid));
    } else if (pt==PotionType::BOOST_DEFENSE) {
      grid->addNewPotion(new BoostDefense(x, y, grid));
    } else if (pt==PotionType::POISON_HEALTH) {
      grid->addNewPotion(new PoisonHealth(x, y, grid));
    } else if (pt==PotionType::RESTORE_HEALTH) {
      grid->addNewPotion(new RestoreHealth(x, y, grid));
    } else if (pt==PotionType::WOUND_ATTACK) {
      grid->addNewPotion(new WoundAttack(x, y, grid));
    } else if (pt==PotionType::WOUND_DEFENSE) {
      grid->addNewPotion(new WoundDefense(x, y, grid));
    }
  }
}
