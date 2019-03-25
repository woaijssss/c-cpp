
#include <iostream>

#include "abstraction.h"
#include "abstraction_imp.h"

using namespace std;

Abstraction::Abstraction()
{

}

Abstraction::~Abstraction()
{

}

RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp)
{
        _imp = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{

}

void RefinedAbstraction::operation()
{
        _imp->operation();
}
