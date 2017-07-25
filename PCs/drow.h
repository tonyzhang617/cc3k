#ifndef DROW_H
#define DROW_H
#include "player_character.h"
#include "../NPCs/elf.h"

class Drow : public PlayerCharacter {
public:
  Drow(int x, int y, Grid *grid);
  void consumePotion(Potion *p) override;
  bool attackedBy(Elf *c) override;
  std::string getRace() override;
};

#endif
