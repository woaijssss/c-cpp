/*************************************************************************
    > File Name: find_if_not.cpp
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

	//与find_if相反
	it = find_if_not(v.begin(), v.end(), f); 
	cerr << *it << endl;

	return 0;
}
