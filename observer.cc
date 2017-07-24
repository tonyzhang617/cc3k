#include "observer.h"
using namespace std;

void Observer::toggleFreeze() {
  observerIsFrozen = !observerIsFrozen;
}

bool Observer::isFrozen() {
  return observerIsFrozen;
}
