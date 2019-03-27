/*
 * vector.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: wenhan
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 *  （1）vector内存动态增长相关函数：
 *          size(),capacity(),reserve(),resize()
 *  （2）vector默认的容量capacity的初始值，以及增长规则是依赖于编译器的；
 */

int main()
{
        vector<int> v;
        cout << v.capacity() << endl;   // 默认容量为0

        vector<int> v1;     // 构造函数给定初始容量
        cout << v1.data() << endl;
        v1.reserve(10);     // 预先分配一块指定大小的控件
        cout << v1.capacity() << endl;  // 此时初始容量为10
        cout << v1.size() << endl;      // 此时元素个数为0

        return 0;
}


