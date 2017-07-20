#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H
#include "../character.h"

class EnemyCharacter: public Character {
public:
  EnemyCharacter(int x, int y, Grid *g);
  void makeMove(Direction dir = Direction::RANDOM) final;
  void attack(Character *c) override;
  void attackedBy(Character *c) override;
  void modifyHP(int n) override;
  char getChar() override;
  // ~EnenmyCharacter() = 0 {}
};

#endif
