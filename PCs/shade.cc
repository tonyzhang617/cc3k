#include "shade.h"
using namespace std;

Shade::Shade(int x, int y, Grid *grid): PlayerCharacter(x, y, grid, 125, 25, 25) {}

string Shade::getRace() {
  return "Shade";
}

int Shade::getScore() {
  return gold*2;
}