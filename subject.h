#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"

class Subject {
  vector<Observer*> observers;
public:
  void notifyObservers();
  void attach(Observer *o);  
};

#endif
