#ifndef GOLD_FACTORY_H
#define GOLD_FACTORY_H
#include "factory.h"

class GoldFactory : public Factory {
  GoldType gts[8];
  void createAt(int x, int y, EntityType type = EntityType::RANDOM_ENTITY) override;
public:
  GoldFactory(Grid *grid);
  void createGold(int x, int y, GoldType gt);
};

#endif
