#ifndef FACTORY_H
#define FACTORY_H
#include "string"
#include "../grid.h"
#include "../enum.h"
#include <cstdlib>

class Factory {
  virtual void createAt(EntityType type = EntityType::RANDOM, int x, int y) = 0;
protected:
  Grid *grid;
  Factory(Grid *grid);
public:
  void createEntity(EntityType type);
};

#endif
