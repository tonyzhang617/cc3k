#include "stair_factory.h"
using namespace std;

StairFactory::StairFactory(Grid *grid): Factory{grid} {}

void StairFactory::createAt(EntityType type, int x, int y) {
  if (type == EntityType::RANDOM) {
    grid->setStair(x, y);
  }
}
