#ifndef GOLD_FACTORY_H
#define GOLD_FACTORY_H
#include "factory.h"

class GoldFactory : public Factory {
  GoldType gts[] = {GoldType::SMALL_HOARD, GoldType::SMALL_HOARD,
                    GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD,
                    GoldType::NORMAL_HOARD, GoldType::NORMAL_HOARD, GoldType::DRAGON_HOARD};
  void createAt(EntityType type = EntityType::RANDOM, int x, int y) override;
public:
  GoldFactory(Grid *grid);
};

#endif
