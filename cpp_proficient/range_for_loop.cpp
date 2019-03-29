/*
 * range_for_loop.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: wenhan
 */

#include <iostream>

using namespace std;

class IntVector;

class Iter {
public:
        Iter(const IntVector* p_vec, int pos)
                : _pos(pos), _p_vec(p_vec)
        {

        }

        ~Iter()
        {
        }

public:
        // 这三个方法组成支持区间迭代的迭代器的基础
        bool operator!=(const Iter& other) const
        {
                return _pos != other._pos;
        }

        int operator*() const;

        const Iter& operator++()
        {
                ++_pos;
                return *this;
        }

private:
        int _pos;
        const IntVector *_p_vec;
};

class IntVector {
public:
        IntVector()
        {

        }

        ~IntVector() {}

public:
        int get(int col) const
        {
                return _data[col];
        }

        Iter begin() const
        {
                return Iter(this, 0);
        }

        Iter end() const
        {
                return Iter(this, 100);
        }

        void set(int index, int val)
        {
                _data[index] = val;
        }

        const int& operator[](int index) const
        {
                return _data[index];
        }

private:
        int _data[100];
};

int Iter::operator *() const
{
        return _p_vec->get(_pos);
}

int main()
{
        IntVector v;
        for (int i = 0; i < 100; i++) {
                v.set(i, i);
        }

//        for (int i: v) {
//                cout << i << endl;
//        }

        const int& d = v[10];
        char s1 = 'a';
        wchar_t s = 'a';
        cout << s << endl;
        cout << sizeof(s1) << endl;
        cout << sizeof(s) << endl;

        return 0;
}

