//
// Created by gotesu on 26/01/18.
//

#ifndef EX7_THREADPOOL_H
#define EX7_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    static ThreadPool * getInstance();
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();

private:
    ThreadPool(int threadsNum);
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    static pthread_mutex_t lock;
    static void *execute(void *arg);
    static ThreadPool* instance;
};


#endif //EX7_THREADPOOL_H
