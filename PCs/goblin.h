#ifndef GOBLIN_H
#define GOBLIN_H
#include "player_character.h"
#include "../NPCs/orcs.h"

class Goblin : public PlayerCharacter {
public:
  Goblin(int x, int y, Grid *grid);
  void slay(Character *c) override;
  void attackedBy(Orcs *c) override;
};

#endif
