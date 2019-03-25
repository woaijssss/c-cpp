
#include <iostream>

#include "product.h"
#include "factory.h"

using namespace std;

Factory::~Factory()
{

}

Factory::Factory()
{

}

ConcreteFactory::ConcreteFactory()
{
        cout<<"ConcreteFactory....."<<endl;
}

ConcreteFactory::~ConcreteFactory()
{

}

Product* ConcreteFactory::createProduct()
{
        return new ConcreteProduct();
}
