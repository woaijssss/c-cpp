/*************************************************************************
    > File Name: find_if.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:01:55 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { return i > 2;};
	vector<int> v{1, 2, 3, 4};
	vector<int>::iterator it;

	//返回第一个满足f条件的迭代器的位置
	it = find_if(v.begin(), v.end(), f); 
	cerr << *it << endl;

	return 0;
}
