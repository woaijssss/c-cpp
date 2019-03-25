
#include "decorator.h"

#include <iostream>

using namespace std;

Component::Component()
{

}

Component::~Component()
{

}

void Component::operation()
{

}

ConcreteComponent::ConcreteComponent()
{

}

ConcreteComponent::~ConcreteComponent()
{

}

void ConcreteComponent::operation()
{
        cout << "ConcreteComponentoperation..." << endl;
}

Decorator::Decorator(Component* com)
        : _com(com)
{

}

Decorator::~Decorator()
{
        delete _com;
}

void Decorator::operation()
{

}

ConcreteDecorator::ConcreteDecorator(Component* com)
        : Decorator(com)
{

}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::operation()
{
        _com->operation();
        this->addedBehavior();
}

void ConcreteDecorator::addedBehavior()
{
        cout << "ConcreteDecorator::AddedBehacior...." << endl;
}
