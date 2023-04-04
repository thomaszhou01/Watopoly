#include "subject.h"
#include "observer.h"

void Subject::attach(Observer* ob){
    observer = ob;
}

void Subject::notifyObservers(){
    observer->notify();
}

Subject::~Subject(){}
