/*************************************************************************
    > File Name: find_first_of.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 30 Aug 2017 10:15:21 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{

	vector<int> v{1, 2, 3, 4};
	vector<int>::iterator it;
	int n[] = {3, 4};

	//返回指向：
	it = find_first_of(v.begin(), v.end(), n, n+3);

	cerr << *it << endl;
	
	return 0;	
}
