/*************************************************************************
    > File Name: copy.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:45:26 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	auto f = [](int i) {cerr << i << endl;};
	auto if_ = [](int i) { return i >= 4; };
	int n[] = {1, 2, 3, 4, 5, 6};
	vector<int> v(6);

	//将n中的元素范围拷贝到v中
//	copy(n, n+ 6, v.begin());
	copy_n(n, 6, v.begin());
//	copy_if(n, n+6, v.begin(), if_);
	copy_backward(v.begin(), v.begin()+3, v.end());

	for_each(v.begin(), v.end(), f);

	return 0;
}
