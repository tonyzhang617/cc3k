#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "factory.h"

class EnemyFactory : public Factory {
  EnemyType ets[18];
  void createAt(int x, int y, EntityType type = EntityType::RANDOM_ENTITY) override;
public:
  EnemyFactory(Grid *grid);
  void createEnemy(int x, int y, EnemyType et);
};

#endif
