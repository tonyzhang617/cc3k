#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Observer {
public:
  virtual void notify(Subject *whoNotified) = 0;
};

#endif
