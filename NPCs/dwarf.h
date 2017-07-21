#ifndef DWARF_H
#define DWARF_H
#include "enemy_character.h"
#include "../PCs/vampire.h"

class Dwarf : public EnemyCharacter {
public:
  Dwarf(int x, int y, Grid *grid);
  bool attackedBy(Vampire *c) override;
  char getChar() override;
};

#endif
