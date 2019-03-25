/*************************************************************************
    > File Name: remove.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:05:31 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) {cerr << i << endl;};
	vector<int> v{1, 2, 3, 4, 5, 10, 2, 9, 3, 2};

	//去掉v中所有与指定值相同的元素
	remove(v.begin(), v.end(), 2);
	
	for_each(v.begin(), v.end(), f);

	return 0;	
}
