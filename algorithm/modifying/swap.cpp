/*************************************************************************
    > File Name: swap.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 11:10:54 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v1{1, 2, 3, 4};
	vector<int> v2{5, 6, 7, 8};

	swap(v1, v2);

	//交换v1和v2中的值。
	for_each(v1.begin(), v1.end(), f);

	return 0;
}
