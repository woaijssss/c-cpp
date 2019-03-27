/*
 * decltype.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: wenhan
 */

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
        using ptrdiff_t = decltype((int*)0 - (int*)0);

        int arr[4];
        int i = 10;
        decltype(i) a;      // a推导为int

        /* 仅仅为i加上了()，就导致类型推导结果的差异；
         * 这是因为，i是一个标记符表达式，根据推到规则1，类型被推导为int；
         * 而(i)为一个左值表达式，所以类型被推导为int&；
         */
        decltype(i) b = 1;    // b推导为int&，必须为其初始化，否则编译错误

        int (c) = 100;
        int c1 = (c);
        cout << c1 << endl;


        return 0;
}


