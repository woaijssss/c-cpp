
#include "subject.h"
#include "observer.h"

#include <iostream>
#include <list>

using namespace std;

Subject::Subject()
{
        //在模板的使用之前一定要 new，创建
        _obvs = new list<Observer*>;
}

Subject::~Subject()
{

}

void Subject::Attach(Observer* obv)
{
        _obvs->push_front(obv);
}

void Subject::Detach(Observer* obv)
{
        if (obv != NULL)
                _obvs->remove(obv);
}

void Subject::Notify()
{
        list<Observer*>::iterator it;
        for (it = _obvs->begin(); it != _obvs->end(); it++) {
                (*it)->Update(this);
        }
}

ConcreteSubject::ConcreteSubject()
{
        _st = '\0';
}

ConcreteSubject::~ConcreteSubject()
{

}

string ConcreteSubject::GetState()
{
        return _st;
}

void ConcreteSubject::SetState(const string& st)
{
        _st = st;
}
