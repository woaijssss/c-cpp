/*************************************************************************
    > File Name: count_if.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:24:57 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { return i < 3; };
	vector<int> v{1, 2, 3, 4, 5};

	//条件计数器 计算v中满足f条件的数量
	cerr << count_if(v.begin(), v.end(), f) << endl;

	return 0;
}
