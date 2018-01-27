//
// Created by gotesu on 25/01/18.
//

#ifndef EX7_TASK_H
#define EX7_TASK_H

/*
 * task interface for Thread pool pattern
 */
class Task {
public:
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //EX7_TASK_H
