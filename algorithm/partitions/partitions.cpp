/*************************************************************************
    > File Name: partitions.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:22:40 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { return (i%2) == 1; };
	auto f1 = [](int i) { cerr << i << endl; };
	vector<int> v{1, 2, 9, 3, 4, 7, 5};
	cerr << "===" << is_partitioned(v.begin(), v.end(), f) << endl;

	//按照f条件，将v中的元素分离开
	vector<int>::iterator it = partition(v.begin(), v.end(), f);


	for_each(v.begin(), v.end(), f1);

	return 0;
}
