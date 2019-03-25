/*************************************************************************
    > File Name: any_of.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 09:44:38 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) {return i > 0;};
	vector<int> v{-1, -2, -3, -4};

	//若f都不满足条件，返回0;否则，相反
	cerr << any_of(v.begin(), v.end(), f) << endl;

	return 0;
}
