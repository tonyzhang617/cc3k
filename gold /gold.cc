#include "gold.h"
#include "../../PCs/player_character.h"
#include "../../PCs/drow.h"
using namespace std;

Gold::Gold(int x, int y, int value): Item{x, y}, value{value} {}

char Gold::getChar() {
  return 'G';
}

void Gold::consumedBy(PlayCharacter * pc) {
  pc->addGold(value);
}

void Gold::consumedBy(Drow * drow) {
  drow->addGold(value);
}
