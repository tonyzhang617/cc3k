#include "dragon.h"
#include "../gold/dragon_hoard.h"
using namespace std;

Dragon::Dragon(int x, int y, Grid *grid, shared_ptr<DragonHoard> hoard):
    EnemyCharacter(x, y, grid), hoard(hoard) {
  hp = 150;
  atk = 20;
  def = 20;
}

char Dragon::getChar() {
  return 'D';
}

void Dragon::notify(Subject *whoNotified) {
  if (!isDead()) {
    int subx = whoNotified->getPosition().first;
    int suby = whoNotified->getPosition().second;
    int hx = hoard->getPosition().first;
    int hy = hoard->getPosition().second;
    if (((abs(subx - x) <= 1 && abs(suby - y) <= 1) ||
        (abs(subx - hx) <= 1 && abs(suby - hy) <= 1)) &&
        !(subx == x && suby == y)) {
      grid->enemyAttack(this);
    } else {
      makeMove();
    }
  }
}

void Dragon::slainBy(Character *c) {
  hoard->freeHoard();
}

string Dragon::getRace() {
  return "dragon";
}
