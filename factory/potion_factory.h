#ifndef POTION_FACTORY_H
#define POTION_FACTORY_H

#include "factory.h"

class PotionFactory : public Factory {
  void createAt(EntityType type = EntityType::RANDOM, int x, int y) override;
public:
  PotionFactory(Grid *grid);
};

#endif
