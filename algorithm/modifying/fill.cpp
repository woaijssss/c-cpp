/*************************************************************************
    > File Name: fill.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 02:17:28 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v{1, 2, 3, 4};
	
	//可以将v中的某一段元素用指定的值（这里是10）替换
//	fill(v.begin()+2, v.end(), 10);

	//从指定迭代器开始，替换2个值
	fill_n(v.begin()+1, 2, 10);

	for_each(v.begin(), v.end(), f);

	return 0;
}
