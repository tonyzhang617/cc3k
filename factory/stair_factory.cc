#include "stair_factory.h"
using namespace std;

StairFactory::StairFactory(Grid *grid): Factory{grid} {}

void StairFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::RANDOM_ENTITY) {
    grid->setStair(x, y);
  }
}
