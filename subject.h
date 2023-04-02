#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <vector>

class Subject{
    public:
        void notifyObservers();
        virtual ~Subject()=0;
};

#endif
