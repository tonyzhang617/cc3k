#include "troll.h"
using namespace std;

Troll::Troll(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 120, 25, 15) {}

void Troll::trollMove() {
  modifyHP(5);
}