/*************************************************************************
    > File Name: none_of.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 09:48:51 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) {return i < 2; };
	vector<int> v{1, 2, 3, 4};

	//如果f返回0，none_of返回1；否则，相反;
	cerr << none_of(v.begin(), v.end(), f) << endl;

	return 0;
}
