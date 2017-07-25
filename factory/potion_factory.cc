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
    createPotion(x, y, pt);
  }
}

void PotionFactory::createPotion(int x, int y, PotionType pt) {
  if (pt==PotionType::BOOST_ATTACK) {
    grid->addNewPotion(shared_ptr<Potion>(new BoostAttack(x, y, grid)));
  } else if (pt==PotionType::BOOST_DEFENSE) {
    grid->addNewPotion(shared_ptr<Potion>(new BoostDefense(x, y, grid)));
  } else if (pt==PotionType::POISON_HEALTH) {
    grid->addNewPotion(shared_ptr<Potion>(new PoisonHealth(x, y, grid)));
  } else if (pt==PotionType::RESTORE_HEALTH) {
    grid->addNewPotion(shared_ptr<Potion>(new RestoreHealth(x, y, grid)));
  } else if (pt==PotionType::WOUND_ATTACK) {
    grid->addNewPotion(shared_ptr<Potion>(new WoundAttack(x, y, grid)));
  } else if (pt==PotionType::WOUND_DEFENSE) {
    grid->addNewPotion(shared_ptr<Potion>(new WoundDefense(x, y, grid)));
  }
}
