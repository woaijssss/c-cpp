
#include "adapter.h"
#include <iostream>

using namespace std;

Target::Target()
{

}

Target::~Target()
{

}

void Target::request()
{
        cout << "Target::request..." << endl;
}

Adaptee::Adaptee()
{

}

Adaptee::~Adaptee()
{

}

void Adaptee::specificRequest()
{
        cout << "Adaptee::specificRequest..." << endl;
}

Adapter::Adapter(Adaptee* ade)
        : _ade(ade)
{

}

Adapter::~Adapter()
{

}

void Adapter::request()
{
        this->specificRequest();
}
