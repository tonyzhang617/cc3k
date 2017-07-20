#ifndef DRAGON_H
#define DRAGON_H
#include "enemy_character.h"

class Dragon : public EnemyCharacter {
public:
  Dragon(int x, int y, Grid *grid);
};

#endif
