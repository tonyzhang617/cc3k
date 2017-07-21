#ifndef ELF_H
#define ELF_H
#include "enemy_character.h"

class Elf : public EnemyCharacter {
public:
  Elf(int x, int y, Grid *grid);
  bool attack(Character *c) override;
  char getChar() override;
};

#endif
