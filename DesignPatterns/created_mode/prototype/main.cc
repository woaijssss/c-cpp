
#include "prototype.h"
#include <iostream>

using namespace std;

int main(void)
{
        Prototype* p = new ConcretePrototype();
        Prototype* p1 = p->clone();

        return 0;
}
