/*************************************************************************
    > File Name: rotate.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:19:04 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v{1, 2, 3, 4, 5, 6};

	//将v.end()-1指向的位置前面的数据拼接到最后，相当于旋转
	rotate(v.begin(), v.end()-1, v.end());

	for_each(v.begin(), v.end(), f);

	return 0;
}
