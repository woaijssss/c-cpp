
#include "decorator.h"

#include <iostream>

using namespace std;

int main(void)
{
        Component* com = new ConcreteComponent();
        Decorator* dec = new ConcreteDecorator(com);

        dec->operation();

        delete dec;

        return 0;
}
