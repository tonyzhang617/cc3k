#include "human.h"
#include "../grid.h"
using namespace std;

Human::Human(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 140;
  atk = 20;
  def = 20;
}

void Human::slainBy(Character *c) {
  c->addGold(legacy);
}

char Human::getChar() {
  return 'H';
}

string Human::getRace() {
  return "human";
}
