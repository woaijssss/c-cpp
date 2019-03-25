/*************************************************************************
    > File Name: merge.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:54:33 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	int first[] = {5, 10, 15, 20, 25};
	int second[] = {50, 40, 30, 20, 10};

	vector<int> v(10);

	sort(first, first+5);
	sort(second, second+5);

	merge(first, first+5, second, second+5, v.begin());
	
	for_each(v.begin(), v.end(), f);

	return 0;
}
