
#include <iostream>

#include "abstract_factory.h"

using namespace std;

int main(void)
{
        AbstractFactory* cf1 = new ConcreteFactory1();
        cf1->createProductA();
        cf1->createProductB();

        AbstractFactory* cf2 = new ConcreteFactory2();
        cf2->createProductA();
        cf2->createProductB();

        return 0;
}
