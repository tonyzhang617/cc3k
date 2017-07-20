#ifndef HALFLING_H
#define HALFLING_H
#include "enemy_character.h"
#include "../character.h"
#include "../PCs/vampire.h"

class Halfling : public EnemyCharacter {
public:
  Halfling(int x, int y, Grid *grid);
  void attackedBy(Character *c) override;
  void attackedBy(Vampire *c) override;
  char getChar() override;
};

#endif
