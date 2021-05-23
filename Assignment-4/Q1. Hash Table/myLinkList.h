//
// Created by SUBHADEEP DUTTA on 28-02-2021.
//

#ifndef PROJ1_MYLINKLIST_H
#define PROJ1_MYLINKLIST_H

class node {
public:
    int data;
    node* next;
};

class myLinkList {
    node* first;

public:
    myLinkList();                   // explicit default constructor
    ~myLinkList();                  // explicit default destructor
    node* createNode();             // create a empty node
    void display();                 // display the linklist
    void insertBeg(int);            // insert at beginning of linklist
    void del(int);                  // delete element from linklist
    bool search(int);               // search element in linklist
    int countNodes();               // count number of nodes
};


#endif //PROJ1_MYLINKLIST_H
