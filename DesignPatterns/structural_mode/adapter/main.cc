
#include "adapter.h"
#include <iostream>

using namespace std;

int main(void)
{
        Adaptee* ade = new Adaptee;
        // 从Adaptee那里"学习"的技能，来实现Target
        Target* adt = new Adapter(ade);

        adt->request();

        return 0;
}
