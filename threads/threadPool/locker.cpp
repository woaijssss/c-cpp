/*
 * locker.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: wenhan
 */

#include "locker.h"

Sem::Sem()
{
        if (sem_init(&_sem, 0, 0)) {
                throw std::exception();     // 抛出异常
        }
}

Sem::~Sem()
{
        sem_destroy(&_sem);
}

int Sem::wait()
{
        return sem_wait(&_sem);
}

int Sem::post()
{
        return sem_post(&_sem);
}

Locker::Locker()
{
        if (pthread_mutex_init(&_mutex, NULL)) {
                throw std::exception();
        }
}

Locker::~Locker()
{
        pthread_mutex_destroy(&_mutex);
}

int Locker::lock()
{
        return pthread_mutex_lock(&_mutex);
}

int Locker::unlock()
{
        return pthread_mutex_unlock(&_mutex);
}

Condition::Condition()
{
        if (pthread_mutex_init(&_mutex, NULL)) {
                throw std::exception();
        }

        if (pthread_cond_init(&_cond, NULL)) {
                throw std::exception();
        }
}

Condition::~Condition()
{
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
}

int Condition::wait()
{
        int ret = 0;
        pthread_mutex_lock(&_mutex);
        ret = pthread_cond_wait(&_cond, &_mutex);
        pthread_mutex_unlock(&_mutex);

        return ret;
}

int Condition::signal()
{
        return pthread_cond_signal(&_cond);
}























