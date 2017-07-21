#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "factory.h"

class EnemyFactory : public Factory {
  EnemyType ets[] = {EnemyType::HUMAN, EnemyType::HUMAN, EnemyType::HUMAN, EnemyType::HUMAN,
                     EnemyType::DWARF, EnemyType::DWARF, EnemyType::DWARF,
                     EnemyType::HALFLING, EnemyType::HALFLING, EnemyType::HALFLING,
                     EnemyType::HALFLING, EnemyType::HALFLING,
                     EnemyType::ELF, EnemyType::ELF, EnemyType::ORCS, EnemyType::ORCS,
                     EnemyType::MERCHANT, EnemyType::MERCHANT};
  void createAt(EntityType type = EntityType::RANDOM, int x, int y) override;
public:
  EnemyFactory(Grid *grid);

};