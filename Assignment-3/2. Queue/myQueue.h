//
// Created by SUBHADEEP DUTTA on 22-02-2021.
//

#ifndef PROJ1_MYQUEUE_H
#define PROJ1_MYQUEUE_H


class myQueue {
    int rear, front, size;
    int* ptr;

public:
    myQueue();              // explicit default constructor
    myQueue(int);           // parameterized constructor
    ~myQueue();             // explicit destructor
    void enqueue(int);      // enqueue method
    void dequeue();         // dequeue method
    void display();         // display method
    bool isEmpty() const;   // check for empty queue
    bool isFull() const;    // check for full queue
};


#endif //PROJ1_MYQUEUE_H
