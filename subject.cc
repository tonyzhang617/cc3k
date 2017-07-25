#include "subject.h"
#include "observer.h"
using namespace std;

void Subject::notifyObservers() {
  for (Observer *o : observers) {
    o->notify(this);
  }
}

void Subject::attach(Observer *o) {
  observers.push_back(o);
}

void Subject::clearAll() {
  observers.clear();
}

void Subject::toggleFreezeAll() {
  for (auto o : observers) {
    o->toggleFreeze();
  }
}

void Subject::detach(Observer *o) {
  for (int i = 0; i < observers.size(); i++) {
    if (observers[i] == o) {
      observers.erase(observers.begin()+i);
    }
  }
}
