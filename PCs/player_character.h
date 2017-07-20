#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "../character.h"
#include "../NPCs/enemy_character.h"

class Item;
class PlayerCharacter : public Character {
  virtual void trollMove(); // for trolls' superpower, called in makeMove
protected:
  const int defaultHP, defaultAtk, defaultDef;
public:
  PlayerCharacter(int x, int y, Grid *g, int dHP, int dAtk, int dDef);
  char getChar() final;
  void makeMove(Direction dir) final;
  virtual void consumePotion(Item *p);
  void resetAtkDef();
  void modifyHP(int n) override;
  void modifyAtk(int n);
  void modifyDef(int n);
  void attack(Character *c) override;
  // virtual ~PlayerCharacter() = 0 {}
};

#endif
