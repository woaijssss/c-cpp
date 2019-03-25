/*************************************************************************
    > File Name: find.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 09:57:24 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { return i == 3;};
	vector<int> v{1, 2, 3, 4};
	vector<int>::iterator it; 

	//find返回一个指向v的迭代器，找到满足条件的值2
	it = find(v.begin(), v.end(), 1);

	cerr << *it << endl;

	return 0;
}
