#ifndef POTION_FACTORY_H
#define POTION_FACTORY_H

#include "factory.h"

class PotionFactory : public Factory {
  void createAt(int x, int y, EntityType type = EntityType::RANDOM_ENTITY) override;
public:
  PotionFactory(Grid *grid);
  void createPotion(int x, int y, PotionType pt);
};

#endif
