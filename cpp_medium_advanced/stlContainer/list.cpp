/*
 * list.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: wenhan
 */

#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

int main()
{
        list<int> l;
        printf("%p\n", &l);

        l.push_front(10);
        printf("%p\n", &l);

        list<int>::iterator it;
        l.erase(it);

        return 0;
}


