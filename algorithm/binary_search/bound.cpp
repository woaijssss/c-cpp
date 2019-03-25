/*************************************************************************
    > File Name: bound.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:42:18 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v{1, 3, 3, 4, 3, 3, 1};

	vector<int>::iterator it;
	vector<int>::iterator it1;

	//用bound之前需要先排序
	sort(v.begin(), v.end());

	//返回第一次出现指定值的位置
	it = lower_bound(v.begin(), v.end(), 3);
	cerr << it - v.begin() << endl;

	it1 = upper_bound(v.begin(), v.end(), 3);
	cerr << it1 - v.begin() << endl;


	return 0;
}
