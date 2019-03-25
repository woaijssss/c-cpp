/*************************************************************************
    > File Name: is_permutation.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:39:26 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1{1, 2, 3, 4, 5};
	vector<int> v2{6, 4, 2, 1, 5};
	
	//比较v1和v2中的元素，有一个不相等就返回0；
	//否则，返回1；   无关元素的顺序
	cerr << is_permutation(v1.begin(), v1.end(), v2.begin()) << endl;

	return 0;
}
