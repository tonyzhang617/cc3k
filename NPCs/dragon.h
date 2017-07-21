#ifndef DRAGON_H
#define DRAGON_H
#include "enemy_character.h"
#include "../grid.h"

class DragonHoard;
class Dragon : public EnemyCharacter {
  DragonHoard *hoard = nullptr;
public:
  Dragon(int x, int y, Grid *grid);
  char getChar() override;
  void notify(Subject *whoNotified) override;
  void setHoard(DragonHoard *dh) override;
};

#endif
