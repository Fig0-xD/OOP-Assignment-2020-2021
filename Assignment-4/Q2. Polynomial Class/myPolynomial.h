//
// Created by SUBHADEEP DUTTA on 08-03-2021.
//

#ifndef PROJ1_MYPOLYNOMIAL_H
#define PROJ1_MYPOLYNOMIAL_H

class Node{

public:
    int exponent;
    int coefficient;
    Node* next;
};


class myPolynomial {

    Node* first;

public:
    myPolynomial();                         //explicit default constructor
    ~myPolynomial();                        //explicit default destructor
    myPolynomial(const myPolynomial&);      //copy constructor
    Node* createNode();                     //create a empty node
    void insertTerm(int, int);              //insert node in LL
    void deleteTerm(int);                   //delete node from LL
    void displayPoly();                     //display LL
    void evalPoly(int);                     //evaluate polynomial with value
    myPolynomial addPoly(const myPolynomial&);      //add two LL
    Node * searchTerm(int) const;           //search a term in LL

};

#endif //PROJ1_MYPOLYNOMIAL_H
