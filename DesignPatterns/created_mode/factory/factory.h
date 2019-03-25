
#ifndef __FACTORY_H__
#define __FACTORY_H__

/* description
   Factory 模式的两个最重要的功能：
   1）定义创建对象的接口，封装了对象的创建；
   2）使得具体化类的工作延迟到了子类中。
   在第一个问题中，我们经常就是声明一个创建对象的接口，并封装了对象的创建过程。
   Factory这里类似于一个真正意义上的工厂（ 生产对象）。
   在第二个问题中，我们需要提供一个对象创建对象的接口，并在子类中提供其具体实现（因为只有在子类中可以决定到底实例化哪一个类）。
 */

class Product;

class Factory {
public:
        virtual ~Factory() = 0;

        virtual Product* createProduct() = 0;

protected:
        Factory();

private:

};

class ConcreteFactory: public Factory {
public:
        ConcreteFactory();
        ~ConcreteFactory();

        Product* createProduct();

protected:

private:
};

#endif  // __FACTORY_H__
