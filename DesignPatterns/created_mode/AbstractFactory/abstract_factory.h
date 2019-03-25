
#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

/* description
   AbstractFactory模式就是用来解决这类问题的：要创建一组相关或者相互依赖的对象。
   AbstractFactory模式关键就是将这一组对象的创建封装到一个用于创建对象的类（ ConcreteFactory）中， 维护这样一个创建类总比维护 n 多相关对象的创建过程要简单的多。
 */

class AbstractProductA;
class AbstractProductB;

class AbstractFactory {
public:
        virtual ~AbstractFactory();
        virtual AbstractProductA* createProductA() = 0;
        virtual AbstractProductB* createProductB() = 0;

protected:
        AbstractFactory();

private:

};

/* 代码说明
   AbstractFactory模式的实现代码很简单，在测试程序中可以看到，当我们要创建一组对象
   (ProductA1，ProductA2)的时候我们只用维护一个创建对象(ConcreteFactory1),大大简化了维护的成本和工作
 */
class ConcreteFactory1: public AbstractFactory {
public:
        ConcreteFactory1();
        ~ConcreteFactory1();
        AbstractProductA* createProductA();
        AbstractProductB* createProductB();

protected:

private:

};

class ConcreteFactory2: public AbstractFactory {
public:
        ConcreteFactory2();
        ~ConcreteFactory2();
        AbstractProductA* createProductA();
        AbstractProductB* createProductB();

protected:

private:

};

#endif  // __ABSTRACT_FACTORY_H__
