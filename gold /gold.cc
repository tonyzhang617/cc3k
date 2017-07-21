#include "gold.h"
#include "../../PCs/player_character.h"
#include "../../PCs/drow.h"
using namespace std;

Gold::Gold(int x, int y, Grid * grid, int value): Item{x, y, grid}, value{value} {}

char Gold::getChar() {
  return 'G';
}

void Gold::consumedBy(PlayCharacter * pc) {
  pc->addGold(value);
}

void Gold::consumedBy(Drow * drow) {
  drow->addGold(value);
}
