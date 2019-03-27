/*
 * threadPool.h
 *
 *  Created on: Mar 25, 2019
 *      Author: wenhan
 */

#ifndef THREADS_THREADPOOL_THREADPOOL_H_
#define THREADS_THREADPOOL_THREADPOOL_H_

#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <queue>
#include <exception>

#include "locker.h"

template<typename T>
class ThreadPool {
public:
        ThreadPool(int num=8, int max_requests=1000);
        ~ThreadPool();

        // 向请求队列中添加请求
        bool append(T* request);
private:
        // 线程执行函数
        static void* worker(void* arg);

        void run();
private:
        int _num;                       // 线程数量
        int _max_request;               // 请求队列的最大容量
        pthread_t* _threads;            // 指向管理线程tid的数组
        std::queue<T*> _work_queue;     // 请求队列
        Locker _queue_locker;           // 保护请求队列的互斥锁
        Sem _queue_state;               // 请求队列中是否有任务需要处理
        bool _stop;                     // 是否结束线程
};

#endif /* THREADS_THREADPOOL_THREADPOOL_H_ */
