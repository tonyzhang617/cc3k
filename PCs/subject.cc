#include "subject.h"
#include "../NPCs/observer.h"
using namespace std;

void Subject::notifyObservers() {
  for (Observer *o : observers) {
    o->notify(this);
  }
}

void Subject::attach(Observer *o) {
  observers.push_back(o);
}
