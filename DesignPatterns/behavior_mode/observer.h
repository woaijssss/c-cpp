
#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "subject.h"
#include <string>

using namespace std;

class Observer {
public:
        virtual ~Observer();
        virtual void Update(Subject* sub) = 0;
        virtual void PrintInfo() = 0;

protected:
        Observer();
        string _st;

private:

};

class ConcreteObserverA: public Observer {
public:
        virtual Subject* GetSubject();
        ConcreteObserverA(Subject* sub);
        virtual ~ConcreteObserverA();

        // 传入Subject作为参数，这样可以让一个View属于多个的Subject.
        void Update(Subject* sub);

        void PrintInfo();

protected:

private:
        Subject* _sub;
};

class ConcreteObserverB: public Observer {
public:
        virtual Subject* GetSubject();
        ConcreteObserverB(Subject* sub);
        virtual ~ConcreteObserverB();

        // 传入Subject作为参数，这样可以让一个View属于多个的Subject.
        void Update(Subject* sub);

        void PrintInfo();

protected:

private:
        Subject* _sub;
};

#endif  // __OBSERVER_H__
