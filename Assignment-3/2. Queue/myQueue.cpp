//
// Created by SUBHADEEP DUTTA on 22-02-2021.
//
#include <iostream>
#include "myQueue.h"

using namespace std;

myQueue::myQueue(): myQueue(5) {}

myQueue::myQueue(int s): front{0}, rear{0}, size{s}
{
    ptr = new int[s];
}

myQueue::~myQueue()
{
    delete[] ptr;
}

void myQueue::enqueue(int element)
{
    if(isFull())
        cout<<"QUEUE OVERFLOW"<<endl;
    else
    {
        ptr[rear++] = element;

        cout<<"ELEMENT ENQUEUED: "<<element<<endl;
    }
}

void myQueue::dequeue()
{
    if(isEmpty())
        cout<<"QUEUE UNDERFLOW"<<endl;
    else
        cout<<"ELEMENT DEQUEUED: "<<ptr[front++]<<endl;
}

void myQueue::display()
{
    if(isEmpty())
        cout<<"QUEUE EMPTY!"<<endl;
    else
    {
        cout<<"[ ";
        for(int i=front; i<rear; i++)
            cout<<ptr[i]<<" ";
        cout<<"]"<<endl;
    }
}

bool myQueue::isEmpty() const
{
    return front == rear;
}

bool myQueue::isFull() const
{
    return rear == size;
}