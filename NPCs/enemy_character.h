#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H
#include "../character.h"
#include <string>
// #include "observer.h"

class EnemyCharacter: public Character {
public:
  EnemyCharacter(int x, int y, Grid *g);
  void makeMove(Direction dir = Direction::RANDOM) final;
  bool attack(Character *c) override;
  bool attackedBy(Character *c) override;
  void modifyHP(int n) override;
  char getChar() override;
  std::string getRace() override;
  // void notify(Subject *whoNotified) override;
  // ~EnenmyCharacter() = 0 {}
};

#endif
