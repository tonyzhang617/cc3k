#include "dragon.h"
using namespace std;

Dragon::Dragon(int x, int y, Grid *grid): EnemyCharacter(x, y, grid) {
  hp = 150;
  atk = 20;
  def = 20;
}
