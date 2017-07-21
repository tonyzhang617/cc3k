#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;
class Subject {
  vector<Observer*> observers;
public:
  void notifyObservers();
  void attach(Observer *o);
  virtual std::pair<int, int> getPosition() = 0;
};

#endif
