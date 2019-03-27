/*
 * threadPool.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: wenhan
 */

#include "threadPool.h"

template<typename T>
ThreadPool<T>::ThreadPool(int num=8, int max_requests=1000)
        : _num(num), _max_request(max_requests), _stop(false), _threads(NULL)
{
        if ((num <= 0) || (max_requests <= 0)) {    // 如果线程数量小于0或请求队列容量小于0
                throw std::exception();
        }

        // 为管理线程tid数组开辟空间
        _threads = new pthread_t[num];

        if (!_threads) {
                throw std::exception();
        }

        // 创建num个线程，将状态设置为分离
        for (int i = 0; i < num; i++) {
                if (pthread_create(_threads+i, NULL, worker, (void*)this) != 0) {
                        delete[] _threads;
                        throw std::exception();
                }

                if (pthread_detach(_threads[i])) {
                        delete[] _threads;
                        throw std::exception();
                }
        }
}

template<typename T>
ThreadPool<T>::~ThreadPool()
{
        if (_threads) {
                delete[] _threads;
                _stop = true;
        }
}

template<typename T>
bool ThreadPool<T>::append(T* request)    // 向请求队列中添加请求
{
        _queue_locker.lock();

        if (_work_queue.size() > _max_request) {    // 确保请求队列任务没有被堆满
                _queue_locker.unlock();
                return false;
        }

        _work_queue.push_back(request);
        _queue_locker.unlock();
        _queue_state.post();    // 每添加一个请求，让信号量增加

        return true;
}

template<typename T>
static void* ThreadPool<T>::worker(void* arg)     // 线程执行函数
{

}

template<typename T>
void ThreadPool<T>::run()
{
        while (!_stop) {
                _queue_state.wait();
                _queue_locker.lock();

                if (_work_queue.empty()) {
                        _queue_locker.unlock();
                        continue;
                }

                T* request = _work_queue.pop();
                _queue_locker.unlock();
                request->process();
        }
}
