#ifndef FACTORY_H
#define FACTORY_H
#include "string"
#include "../grid.h"
#include "../enum.h"
#include <cstdlib>
#include <memory>

class Factory {
  virtual void createAt(int x, int y, EntityType type = EntityType::RANDOM_ENTITY) = 0;
protected:
  Grid *grid;
  Factory(Grid *grid);
public:
  void createEntity(EntityType type = EntityType::RANDOM_ENTITY);
};

#endif
