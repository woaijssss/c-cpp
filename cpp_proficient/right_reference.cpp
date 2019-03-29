/*
 * right_reference.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: wenhan
 */

#include <iostream>
#include <utility>

using namespace std;

int main()
{
        int &&p = 10;
        cout << p << endl;

//        int &p1 = 10;     // 报错
        int p1 = 100;
        int&& p2 = 200;
        cout << p1 << endl;
        cout << p2 << endl;
        p2 = std::move(p1);
        cout << p1 << endl;

        return 0;
}


