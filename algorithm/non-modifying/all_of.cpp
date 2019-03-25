/*************************************************************************
    > File Name: all_of.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 09:34:29 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int main(void)
{
	auto f = [](int i) { return i % 2; };
	vector<int> a{0, 3, 5, 7};

	//如果f返回真，all_of返回真；否则，相反
	//f有0返回0
	cerr << all_of(a.begin(), a.end(), f) << endl;

	return 0;
}
