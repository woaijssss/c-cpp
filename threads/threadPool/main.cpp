/*
 * main.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: wenhan
 */

#include <iostream>

#include "threadPool.h"

using namespace std;

template <class T>
class ShareFromThis {
public:
        template <class T>
        ShareFromThis(T* t) {}

        ~ShareFromThis() {}
private:

};

class A: ShareFromThis<A> {
        using INT = int;
public:
        A() { _i = 100; }
        ~A() {}

public:
        void run()
        {
                cout << "++++++++" << endl;
        }

private:
        INT _i;
};

template <typename T>
void cb(T* t)
{
        t();
}

int main(void)
{
        cb(A::run);

        return 0;
}


