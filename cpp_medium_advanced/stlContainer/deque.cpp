/*
 * deque.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: wenhan
 */

#include <deque>
#include <iostream>

using namespace std;

int main()
{
        deque<int> de;
        de.push_back(10);
        de.push_back(20);
        de.push_back(20);
        de.push_back(20);
        de.push_back(20);
        de.push_back(20);
        de.push_back(20);

        deque<int>::iterator it = de.begin();

        cout << &it << endl;
        it = de.erase(it);
        cout << &it << endl;

        cout << *it << endl;

        return 0;
}


