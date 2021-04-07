//
// Created by SUBHADEEP DUTTA on 17-02-2021.
//
#include <iostream>
#include "myStack.h"

using namespace std;

myStack::myStack() : myStack(5) {}

myStack::myStack(int n)
{
    size = n;
    top = 0;
    ptr = new int[n];
}

myStack::~myStack()
{
    delete[] ptr;
}

void myStack::push(int element)
{
    if(isfull())
    {
        cout<<"STACK OVERFLOW"<<endl;
        return;
    }

    ptr[top++] = element;
    cout<<"ELEMENT PUSHED: "<<element<<endl;
}

void myStack::pop()
{
    if (isempty())
    {
        cout<<"STACK UNDERFLOW"<<endl;
    }
    else
        cout<<"ELEMENT POPPED: "<<ptr[--top]<<endl;
}

void myStack::display()
{
    if(isempty())
        cout<<"STACK EMPTY!"<<endl;
    else
    {
        for(int i = top-1; i >= 0; i--)
            cout<<"[ "<<ptr[i]<<" ]"<<endl;
    }
}

bool myStack::isempty() const
{
    return top == 0;
}

bool myStack::isfull() const
{
    return top == size;
}