#ifndef ORCS_H
#define ORCS_H
#include "enemy_character.h"

class Orcs : public EnemyCharacter {
public:
  Orcs(int x, int y, Grid *grid);
  void attack(Character *c) override;
  char getChar() override; 
};

#endif
