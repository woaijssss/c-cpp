/*
 * locker.h
 *
 *  Created on: Mar 25, 2019
 *      Author: wenhan
 */

#ifndef THREADS_THREADPOOL_LOCKER_H_
#define THREADS_THREADPOOL_LOCKER_H_

#include <exception>    // 异常类库
#include <pthread.h>    // c语言线程库
#include <semaphore.h>  // 信号量库

// 信号量
class Sem {
public:
        Sem();
        ~Sem();

public:
        int wait();
        int post();

private:
        sem_t _sem;
};

// 互斥锁
class Locker {
public:
        Locker();
        ~Locker();

public:
        int lock();
        int unlock();

private:
        pthread_mutex_t _mutex;
};

// 条件变量
class Condition {
public:
        Condition();
        ~Condition();

public:
        // 阻塞正在调用的线程
        int wait();

        // 在等待指定条件变量的任意数量的线程中，唤醒其中一个线程
        int signal();

private:
        pthread_mutex_t _mutex;
        pthread_cond_t _cond;
};

#endif /* THREADS_THREADPOOL_LOCKER_H_ */
