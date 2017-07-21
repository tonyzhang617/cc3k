#include "item.h"
using namespace std;

Item::Item(int x, int y): x{x}, y{y} {}


std::pair<int, int> Item::getPosition() {
  return make_pair(x, y);
}
