/*************************************************************************
    > File Name: replace.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 02:09:42 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) { cerr << i << endl; };
	vector<int> v{1, 2, 3, 4};
	
	//将v中含有2的元素全部替换成20
//	replace(v.begin(), v.end(), 2, 20);

	//将v中满足条件的元素全部替换成100
	//replace_if(v.begin(), v.end(), [](int i) {return i%4==0;}, 100);
	
	int n[] = {4, 5, 6, 7, 8};
	vector<int> v2(sizeof(n)/5);
	replace_copy(n, n+5, v2.begin(), 6, 99);
	for_each(v2.begin(), v2.end(), f);

	for_each(v.begin(), v.end(), f);

	return 0;
}
