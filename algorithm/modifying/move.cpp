/*************************************************************************
    > File Name: move.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 11:08:14 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v1{1, 2, 3, 4};
	vector<int> v2(v1.size());

	move(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), f);

	return 0;
}
