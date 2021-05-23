//
// Created by SUBHADEEP DUTTA on 09-03-2021.
//

#ifndef PROJ1_MYHASHING_H
#define PROJ1_MYHASHING_H

#include "myLinkList.h"

class myHashing {
    myLinkList* ptr;
    int size;

    int hashFunc(int);      //hash->modular method
    int myhashFunc(int);    //hash->multiplication method

public:
    myHashing();            //explicit default constructor
    myHashing(int);         //parameterized constructor
    ~myHashing();           //explicit default destructor
    void insert(int);       //insert for modular method
    void myinsert(int);     //insert for multiplication method
    bool search(int);       //search for modular method
    bool mysearch(int);     //search for multiplication method
    void del(int);          //delete for modular method
    void mydel(int);        //delete for multiplication method
    void display();         //display method
    double TableLoadDistribution();   //shows load distribution
};


#endif //PROJ1_MYHASHING_H
