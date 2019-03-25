
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

/* description
   Singleton模式经常和Factory（ AbstractFactory）模式在一起使用，
   因为系统中工厂对象一般来说只要一个
 */

class Singleton {
public:
        static Singleton* instance();

protected:
//private:
        /*
          Singleton不可以被实例化，因此我们将其构造函数声明为protected或者直接声明为private
         */
        Singleton();

private:
        static Singleton* _instance;
};

#endif  // __SINGLETON_H__
