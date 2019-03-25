/*************************************************************************
    > File Name: transform.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 02:03:10 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { return i + 1; };
	auto f1 = [](int i) { cerr << i << endl; };
	vector<int> v1{1, 2, 3, 4};
	vector<int> v2(v1.size());

	//transform对v1每个元素做f操作，把结果放到v2中
	transform(v1.begin(), v1.end(), v2.begin(), f);

	for_each(v2.begin(), v2.end(), f1);

	return 0;
}
