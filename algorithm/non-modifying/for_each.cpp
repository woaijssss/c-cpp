/*************************************************************************
    > File Name: for_each.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 09:54:53 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i+1 << endl;};
	vector<int> v{1, 2, 3, 4};

	//对v中每个元素进行f的操作
	for_each(v.begin(), v.end(), f);

	return 0;
}
