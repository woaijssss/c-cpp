
#include "observer.h"
#include "subject.h"
#include <iostream>
#include <string>

using namespace std;

Observer::Observer()
{
        _st = '\0';
}

Observer::~Observer()
{

}

ConcreteObserverA::ConcreteObserverA(Subject* sub)
{
        _sub = sub;
        _sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
        _sub->Detach(this);
        if (_sub != NULL) {
                delete _sub;
        }
}

Subject* ConcreteObserverA::GetSubject()
{
        return _sub;
}

void ConcreteObserverA::Update(Subject* sub)
{
        _st = sub->GetState();
        PrintInfo();
}

void ConcreteObserverA::PrintInfo()
{
        cout << "ConcreteObserverA observer...." << _sub->GetState() << endl;
}



ConcreteObserverB::ConcreteObserverB(Subject* sub)
{
        _sub = sub;
        _sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
        _sub->Detach(this);
        if (_sub != NULL) {
                delete _sub;
        }
}

Subject* ConcreteObserverB::GetSubject()
{
        return _sub;
}

void ConcreteObserverB::Update(Subject* sub)
{
        _st = sub->GetState();
        PrintInfo();
}

void ConcreteObserverB::PrintInfo()
{
        cout << "ConcreteObserverB observer...." << _sub->GetState() << endl;
}
