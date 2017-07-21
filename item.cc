#include "item.h"
using namespace std;

Item::Item(int x, int y, Grid *grid): x{x}, y{y}, grid{grid} {}


std::pair<int, int> Item::getPosition() {
  return make_pair(x, y);
}
