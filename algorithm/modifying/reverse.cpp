/*************************************************************************
    > File Name: reverse.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 03:15:21 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) {cerr << i << endl;};
	vector<int> v{1, 2, 3, 4, 5};
	vector<int> v1(v.size());
	
	//将v的顺序倒置
	//reverse(v.begin(), v.end());
	
	//将v拷贝到v1并将顺序倒置，v本身不变
	reverse_copy(v.begin(), v.end(), v1.begin());

	for_each(v.begin(), v.end(), f);

	return 0;
}
