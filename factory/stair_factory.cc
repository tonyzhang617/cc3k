#include "stair_factory.h"
using namespace std;

StairFactory::StairFactory(Grid *grid): Factory{grid} {}

void StairFactory::createAt(int x, int y, EntityType type) {
  if (type == EntityType::RANDOM_ENTITY) {
    createStair(x, y);
  }
}

void StairFactory::createStair(int x, int y) {
  grid->setStair(x, y);
}
