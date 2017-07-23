#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Subject {
  std::vector<Observer*> observers;
public:
  void notifyObservers();
  void attach(Observer *o);
  void clearAll();
  virtual std::pair<int, int> getPosition() = 0;
};

#endif
