
#include <iostream>

#include "abstraction_imp.h"

using namespace std;

AbstractionImp::AbstractionImp()
{

}

AbstractionImp::~AbstractionImp()
{

}

void AbstractionImp::operation()
{
        cout<<"AbstractionImp....imp..."<<endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{

}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{

}

void ConcreteAbstractionImpA::operation()
{
        cout<<"ConcreteAbstractionImpA..."<<endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{

}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{

}

void ConcreteAbstractionImpB::operation()
{
        cout<<"ConcreteAbstractionImpB...."<<endl;
}
