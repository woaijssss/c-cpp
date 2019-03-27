/*
 * auto.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: wenhan
 */

#include <iostream>
#include <vector>
#include <typeinfo>

#include <string.h>

using namespace std;

template<typename _Tx, typename _Ty>
void multiply(_Tx x, _Ty y)
{
        auto v = x*y;
        std::cout << v << std::endl;
        std::cout << typeid(v).name() << std::endl;
}

/* 说明：
 *  - 当模板函数的返回值依赖于模板的参数时，依旧无法在编译代码前确定模板参数的类型，也就无法知道返回值的类型；
 *  - decltype操作符：用于查询表达式的数据类型，也是c++标准引入的新运算符，目的是解决泛型编程中，有些类型由模板参数决定，而难以表示它的问题；
 *  - auto在这里的作用称为“返回值占位符”，它只是为函数返回值占了一个位置，真正的返回值是后面的decltype(_Tx*_Ty)，
 *      如果没有后置，则函数声明为：
 *          decltype(x*y)getMultiply(_Tx x, _Ty y)  // 但是此时x和y没有声明，所以无法编译通过；
 *
 */
template<typename _Tx, typename _Ty>
auto getMultiply(_Tx x, _Ty y)->decltype(x*y)
{
        return x*y;
}

#if 0   // c++11错误，c++14可以使用auto参数
void func(auto a)
{

}
#endif

int main()
{
        std::vector<int> v;
        for (auto it = v.begin(); it != v.end(); ++it) {

        }

        multiply(10L, 20.33L);
        auto res = getMultiply(10L, 20.33L);
        std::cout << res << std::endl;
        std::cout << typeid(res).name() << std::endl;

// 以下为文档中的注意事项：
        // 1.
        auto a4 = 10, a5 = 20, a6 = 30;
//        auto b4 = 10, b5 = 20, b6 = 'a';  // 错误，没有推导为同一类型

        // 2.
        int a = 10;
        int &b = a;
        auto c = b;     // c的类型为int，而不是int&
        auto &d = b;    // 此时d的类型为int&
        c = 100;        // a = 10;
        cout << "a: " << a << endl;
        d = 100;        // a = 100;
        cout << "a: " << a << endl;

        // 3.
        const int a1 = 10;
        auto b1 = a1;       // b1类型为int，而不是const int
        const auto c1 = a1; // c1的类型为const int
        b1 = 100;
//        c1 = 100;     // 非法

        // 4.
        const int a2 = 10;
        auto &b2 = a2;      // 因为auto带上&，则不去除const，b2类型为const int
//        b2 =100;    // 非法

        // 5.
        int a3[3] = {1, 2, 3};
        auto b3 = a3;       // b3的类型为int*
        cout << "b3 type: " << typeid(b3).name() << endl;
        cout << "b3 size: " << sizeof(b3) << endl;

        // 6.
        int a7[3] = {1, 2, 3};
        auto &b7 = a7;      // b7的类型为int [3]，数组类型
        cout << "b7 type: " << typeid(b7).name() << endl;
        cout << "b7 size: " << sizeof(b7) << endl;

        return 0;
}


