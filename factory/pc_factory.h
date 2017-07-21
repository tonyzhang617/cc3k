#ifndef PC_FACTORY_H
#define PC_FACTORY_H

#include "factory.h"

class PCFactory : public Factory {
  void createAt(EntityType type = EntityType::SHADE, int x, int y) override;
public:
  PCFactory(Grid *grid);
};

#endif