//
// Created by gotesu on 26/01/18.
//
#include "ThreadPool.h"
#include <unistd.h>
#define THREADS_NUM 5
//singelton locking and instance mechanism
ThreadPool* ThreadPool::instance = 0;
pthread_mutex_t ThreadPool::lock;

ThreadPool::ThreadPool(int threadsNum) :
        stopped(false) {
    threads = new pthread_t[threadsNum];
    for (int i = 0; i < threadsNum; i++) {
        pthread_create(threads + i, NULL, execute,
                       this);
    }
    pthread_mutex_init(&lock, NULL);
}
void* ThreadPool::execute(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->executeTasks();
}
void ThreadPool::addTask(Task *task) {
    tasksQueue.push(task);
}

void ThreadPool::executeTasks() {
    while (!stopped) {
        pthread_mutex_lock(&lock);
        if (!tasksQueue.empty()) {
            Task* task = tasksQueue.front();
            tasksQueue.pop();
            pthread_mutex_unlock(&lock);
            task->execute();
            delete task;
        }
        else {
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
}
void ThreadPool::terminate() {
    pthread_mutex_destroy(&lock);
    stopped = true;
}
ThreadPool::~ThreadPool() {
    delete[] threads;
    //we need to delete all tasks on queue.
    while(!tasksQueue.empty()) {
        Task* task = tasksQueue.front();
        tasksQueue.pop();
        delete task;
    }
    //note: threads would be automaticly released when main thread dies.
}

ThreadPool *ThreadPool::getInstance() {
        if (instance == 0) {
            pthread_mutex_lock(&lock);
            if (instance == 0) {
                instance = new ThreadPool(THREADS_NUM);
            }
            pthread_mutex_unlock(&lock);
        }
        return instance;
}
