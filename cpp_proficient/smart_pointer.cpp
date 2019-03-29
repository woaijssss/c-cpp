/*
 * smart_pointer.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: wenhan
 */

#include <memory>
#include <iostream>

using namespace std;

int main()
{
#if 1   // shared_ptr
        {
                int a = 10;
                shared_ptr<int> ptra = make_shared<int>(a);
                shared_ptr<int> ptra2(ptra);    // copy
                cout << ptra.use_count() << endl;

                int b = 20;
                int *pb = &a;
//        shared_ptr<int> ptrb = pb;    // error
                shared_ptr<int> ptrb = make_shared<int>(b);
                ptra2 = ptrb;   // assign（分配）
                pb = ptrb.get();    // 获取原始指针

                cout << ptra.use_count() << endl;
                cout << ptrb.use_count() << endl;
        }
#endif

#if 1   // unique_ptr
        {
                unique_ptr<int> uptr(new int(10));  // 绑定动态对象
//                unique_ptr<int> uptr2 = uptr;     // 不能赋值
//                unique_ptr<int> uptr2(uptr);      // 不能拷贝
                unique_ptr<int> uptr2 = std::move(uptr);   // 转义所有权
                uptr2.release();    // 释放所有权
        }
        // 超过uptr的作用域，内存释放；
#endif

#if 1   // weak_ptr
        {
                shared_ptr<int> sh_ptr = make_shared<int>(10);
                cout << sh_ptr.use_count() << endl;

                weak_ptr<int> wp(sh_ptr);
                cout << wp.use_count() << endl;

                if (!wp.expired()) {
                        shared_ptr<int> sh_ptr2 = wp.lock();    // 获得另一个shared_ptr
                        *sh_ptr = 100;
                        cout << *sh_ptr << endl;
                        cout << wp.use_count() << endl;
                }
        }
        // delete释放内存
#endif

        return 0;
}
