/*************************************************************************
    > File Name: count.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:23:02 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v{1, 2, 3, 4, 3, 3, 5};


	//计数器 计算3在v中出现的次数
	cerr << count(v.begin(), v.end(), 3) << endl;

	return 0;
}
