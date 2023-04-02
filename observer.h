#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

class Observer{
    virtual void notify(Subject * subject) = 0;
    virtual ~Observer() {}
};

#endif
