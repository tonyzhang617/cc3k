#ifndef HUMAN_H
#define HUMAN_H
#include "enemy_character.h"

class Human : public EnemyCharacter {
  const int legacy = 4;
public:
  Human(int x, int y, Grid *grid);
  void slainBy(Character *c) override;
  char getChar() override;
};

#endif
