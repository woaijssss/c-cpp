
#include <iostream>

#include "abstraction.h"
#include "abstraction_imp.h"

/* description
   Bridge模式将抽象和实现分别独立实现，在代码中就是Abstraction类和AbstractionImp类。
   Bridge是设计模式中比较复杂和难理解的模式之一，也是OO开发与设计中经常会用到的模式之一。
   使用组合(委托)的方式将抽象和实现彻底地解耦,这样的好处是抽象和实现可以分别独立地变化,系统的耦合性也得到了很好的降低.
   将抽象部分与它的实现部分分离,使得它们可以独立地变化.
 */

using namespace std;

int main(void)
{
        AbstractionImp* imp = new ConcreteAbstractionImpA();
        Abstraction* abs = new RefinedAbstraction(imp);

        abs->operation();

        return 0;
}
