#ifndef STAIR_FACTORY_H
#define STAIR_FACTORY_H
#include "factory.h"

class StairFactory : public Factory {
  void createAt(EntityType type = EntityType::RANDOM, int x, int y) override;
public:
  StairFactory(Grid *grid);
};

#endif
