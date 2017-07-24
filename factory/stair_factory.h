#ifndef STAIR_FACTORY_H
#define STAIR_FACTORY_H
#include "factory.h"

class StairFactory : public Factory {
  void createAt(int x, int y, EntityType type = EntityType::RANDOM_ENTITY) override;
public:
  StairFactory(Grid *grid);
  void createStair(int x, int y);
};

#endif
