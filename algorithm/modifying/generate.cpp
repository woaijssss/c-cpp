/*************************************************************************
    > File Name: generate.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 02:43:28 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
	srand(unsigned (time(0)));
	auto f = [](int i) { cerr << i << endl; };
	auto f2 = []() { return rand()%100; };
	vector<int> v(8);
	
	//这里生成随机数，并将值赋给v
	generate(v.begin(), v.end(), f2);

	for_each(v.begin(), v.end(), f);

	return 0;
}
