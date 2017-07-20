#ifndef CHARACTER_H
#define CHARACTER_H
#include <algorithm>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include "enum.h"

class Grid;
class Elf;
class Vampire;
class Orcs;
class Character {
protected:
  // const int HP, ATK, DEF;
  int x, y;
  int hp, atk, def;
  int gold = 0;
  Grid *grid;

public:
  Character(int x, int y, Grid *g);
  bool isDead();
  std::pair<int, int> getPosition();
  void addGold(int n);
  void printStatus();
  virtual void makeMove(Direction dir) = 0;
  virtual char getChar() = 0;
  virtual void attack(Character *c) = 0;
  virtual void attackedBy(Character *c);
  virtual void attackedBy(Elf *c);
  virtual void attackedBy(Vampire *c);
  virtual void attackedBy(Orcs *c);
  virtual void slay(Character *c);
  virtual void slainBy(Character *c);
  virtual void modifyHP(int n);

  int getHp() const;
  int getAtk() const;
  int getDef() const;
  // virtual ~Character() = 0;
};

#endif
