
#include <iostream>

#include "abstract_factory.h"
#include "product.h"

using namespace std;

AbstractFactory::AbstractFactory()
{

}

AbstractFactory::~AbstractFactory()
{

}

ConcreteFactory1::ConcreteFactory1()
{

}

ConcreteFactory1::~ConcreteFactory1()
{

}

AbstractProductA* ConcreteFactory1::createProductA()
{
        return new ProductA1();
}

AbstractProductB* ConcreteFactory1::createProductB()
{
        return new ProductB1();
}

ConcreteFactory2::ConcreteFactory2()
{

}

ConcreteFactory2::~ConcreteFactory2()
{

}

AbstractProductA* ConcreteFactory2::createProductA()
{
        return new ProductA2();
}

AbstractProductB* ConcreteFactory2::createProductB()
{
        return new ProductB2();
}
