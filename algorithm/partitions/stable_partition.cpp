/*************************************************************************
    > File Name: stable_partition.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:28:56 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	auto f1 = [](int i) { return (i%2) == 1; };
	vector<int> v{1, 2, 3, 4, 5};
	
	vector<int>::iterator it = stable_partition(v.begin(), v.end(), f1);
	cerr << *it << "=====" << endl;

	for_each(v.begin(), v.end(), f);

	return 0;
}
