
#include <functional>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class A: public std::enable_shared_from_this<A>
{
public:
	std::function<void(const int&)> init()
	{
		std::function<void(const int&)> f = std::bind(&A::func, shared_from_this(), std::placeholders::_1);
		return f;
	}
	
	void func(const int& i)
	{
		cout << "func" << endl;
	}
};

int main()
{
	A* a = new A();
	std::function<void(const int&)> f = a->init();
	/* 多线程时，当对象指针被析构后，另一个线程再调用该对象的方法时，使用了 shared_from_this() 会报错: bad_weak_ptr */
	delete a;
	f(10);

	return 0;
}
