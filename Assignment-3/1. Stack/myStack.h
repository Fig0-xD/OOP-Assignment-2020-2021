//
// Created by SUBHADEEP DUTTA on 17-02-2021.
//

#ifndef PROJ1_MYSTACK_H
#define PROJ1_MYSTACK_H


class myStack
{
    int* ptr;
    int size, top;

public:
    myStack();                  // explicit default constructor
    myStack(int n);             // parameterised constructor
    ~myStack();                 // explicit destructor
    void push(int);             // stack push method
    void pop();                 // stack pop method
    void display();             // stack display method
    bool isempty() const;       // check for empty stack
    bool isfull() const;        // check for full stack
};


#endif //PROJ1_MYSTACK_H
