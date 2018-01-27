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
    /*
     * getInstance
     * using singelton pattern.
     */
    static ThreadPool * getInstance();
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();

private:
    /*
     * threadpool uses a fixed number of threads
     * with the Thread pool pattern.
     */
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
