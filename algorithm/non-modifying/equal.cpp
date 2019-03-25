/*************************************************************************
    > File Name: equal.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:29:49 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1{1, 2, 3 ,4};
	vector<int> v2{1, 2, 3 ,4};
	int n[] = {1, 2, 3, 4 };

	//比较STL和数组，如果STL范围内的值与数组n都相同，返回1；
	//否则，返回0
	cerr << equal(v1.begin(), v1.end(), v2.begin()) << endl;

	return 0;
}
