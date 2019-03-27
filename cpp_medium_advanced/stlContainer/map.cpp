/*
 * map.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: wenhan
 */

#include <map>
#include <iostream>

using namespace std;

int main()
{
        map<int, bool> m;   // 默认value值都false
        m[1];

        cout << m[1] << endl;
        cout << m.size() << endl;

        return 0;
}


