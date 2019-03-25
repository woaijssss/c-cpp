
#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <list>
#include <string>

using namespace std;

class Observer;

class Subject {
public:
        virtual ~Subject();
        virtual void Attach(Observer* obv);
        virtual void Detach(Observer* obv);
        virtual void Notify();
        virtual void SetState(const string& st) = 0;
        virtual string GetState() = 0;

protected:
        Subject();

private:
        list<Observer*>* _obvs;
};

class ConcreteSubject: public Subject {
public:
        ConcreteSubject();
        virtual ~ConcreteSubject();
        virtual string GetState();
        virtual void SetState(const string& st);

protected:

private:
        string _st;
};

#endif  // __SUBJECT_H__
