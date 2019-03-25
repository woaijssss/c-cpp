/*************************************************************************
    > File Name: sort.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:36:58 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v{3, 5, 2, 1, 9, 8};

	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), f);

	return 0;
}
