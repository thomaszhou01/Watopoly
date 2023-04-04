#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <vector>

class Observer;

class Subject{
    Observer* observer;
    public:
        void attach(Observer* ob);
        void notifyObservers();
        virtual ~Subject()=0;
};

#endif
