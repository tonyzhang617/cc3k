#ifndef ELF_H
#define ELF_H
#include "enemy_character.h"

class Elf : public EnemyCharacter {
public:
  Elf(int x, int y, Grid *grid);
  void attack(Character *c) override;
};

#endif
