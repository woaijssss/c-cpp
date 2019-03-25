
#include <iostream>

#include "factory.h"
#include "product.h"

using namespace std;

int main(void)
{
        Factory* fac = new ConcreteFactory();
        Product* p = fac->createProduct();

        return 0;
}
