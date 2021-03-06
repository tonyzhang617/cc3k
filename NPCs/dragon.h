#ifndef DRAGON_H
#define DRAGON_H
#include "enemy_character.h"
#include "../grid.h"

class DragonHoard;
class Dragon : public EnemyCharacter {
  std::shared_ptr<DragonHoard> hoard = nullptr;
public:
  Dragon(int x, int y, Grid *grid, std::shared_ptr<DragonHoard> hoard);
  char getChar() override;
  void notify(Subject *whoNotified) override;
  void slainBy(Character *c) override;
  std::string getRace() override;
};

#endif
