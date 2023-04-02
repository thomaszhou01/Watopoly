#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

class Observer{
    virtual void notify() = 0;
    virtual ~Observer();
};

#endif
