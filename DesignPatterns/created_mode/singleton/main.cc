
#include <iostream>

#include "singleton.h"

using namespace std;

int main(void)
{
        Singleton* sgn = Singleton::instance();
        Singleton* sgn1 = Singleton::instance();


        return 0;
}
