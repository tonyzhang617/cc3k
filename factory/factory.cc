#include "factory.h"

using namespace std;

Factory::Factory(Grid *grid): grid{grid} {}

void Factory::createEntity(EntityType type) {
  int x, y;
  while (1) {
    x = rand() % grid->WIDTH;
    y = rand() % grid->HEIGHT;
    CellType ct = grid->getCellTypeAt(x, y);
    if (ct == CellType::FLOOR) break;
  }
  createAt(x, y, type);
}
