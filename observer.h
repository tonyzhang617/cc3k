#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Observer {
bool observerIsFrozen = false;
public:
  virtual void notify(Subject *whoNotified) = 0;
  void toggleFreeze();
  bool isFrozen();
};

#endif
