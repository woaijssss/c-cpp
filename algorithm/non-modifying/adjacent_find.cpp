/*************************************************************************
    > File Name: adjacent_find.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:20:13 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v{1, 2, 3, 4, 5, 6};
	vector<int>::iterator it;

	it = adjacent_find(v.begin(), v.end());
	cerr << *it << endl;

	return 0;
}
