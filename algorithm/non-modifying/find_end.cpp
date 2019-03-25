/*************************************************************************
    > File Name: find_end.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:07:50 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i, int j) {return i == j;}; 
	vector<int> v{5, 2, 3, 4};
	vector<int>::iterator it;
	int n[] = {1, 2, 3};

	//判断n是否是v的子列，如果是，则返回指向v子列的迭代器
	it = find_end(v.begin(), v.end(), n, n+3);
	cerr << *it << endl;

	return 0;
}
