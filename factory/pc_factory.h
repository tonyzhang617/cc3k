#ifndef PC_FACTORY_H
#define PC_FACTORY_H

#include "factory.h"

class PCFactory : public Factory {
  void createAt(int x, int y, EntityType type = EntityType::SHADE) override;
public:
  PCFactory(Grid *grid);
};

#endif