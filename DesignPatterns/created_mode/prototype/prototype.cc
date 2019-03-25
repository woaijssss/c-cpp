
#include "prototype.h"
#include <iostream>

using namespace std;

Prototype::Prototype()
{

}

Prototype::~Prototype()
{

}

ConcretePrototype::ConcretePrototype()
{

}
ConcretePrototype::~ConcretePrototype()
{

}
ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{
        cout << "ConcretePrototypecopy ..." << endl;
}

Prototype* ConcretePrototype::clone() const
{
        return new ConcretePrototype(*this);
}
