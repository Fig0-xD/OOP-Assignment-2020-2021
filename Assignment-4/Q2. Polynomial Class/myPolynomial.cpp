//
// Created by SUBHADEEP DUTTA on 08-03-2021.
//

#include <iostream>
#include <cmath>
#include "myPolynomial.h"

using namespace std;

myPolynomial::myPolynomial(): first{nullptr} {}
myPolynomial::~myPolynomial()
{
    Node* current = first;
    Node* next = nullptr;

    while(current!= nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    first = nullptr;
}

myPolynomial::myPolynomial(const myPolynomial& P): myPolynomial()
{
    Node* trav1 = P.first;
    Node* trav2{nullptr};


    while(trav1 != nullptr)
    {
        Node* temp = createNode();
        temp->coefficient = trav1->coefficient;
        temp->exponent = trav1->exponent;

        if(first == nullptr)
        {
            first = temp;
            trav2 = first;
            trav1 = trav1->next;
            continue;
        }

        trav2->next = temp;
        trav2 = temp;

        trav1 = trav1->next;
    }

}

Node* myPolynomial::createNode()
{
    Node* ptr = new Node;
    ptr->exponent = 0;
    ptr->coefficient = 0;
    ptr->next = nullptr;
    return ptr;
}

void myPolynomial::insertTerm(int coefficient, int exponent)
{
    if(searchTerm(exponent))                                //if term already present
    {
        Node* ptr = searchTerm(exponent);
        ptr->coefficient += coefficient;
    }
    else if(first == nullptr or first->exponent < exponent) //if LL empty or term greater than first term
    {
        Node* temp = createNode();
        temp->exponent = exponent;
        temp->coefficient = coefficient;

        temp->next = first;
        first = temp;
    }
    else if(first->exponent > exponent and first->next == nullptr)  //term less than first term
    {                                                               //but 2nd node is empty
        Node* temp = createNode();
        temp->exponent = exponent;
        temp->coefficient = coefficient;

        first->next = temp;
    }
    else                                                            //for all other cases
    {
        Node* before = first;
        Node* current = first->next;

        while(current->next != nullptr)
        {
            if(before->exponent > exponent and current->exponent < exponent)
            {
                Node* temp = createNode();
                temp->exponent = exponent;
                temp->coefficient = coefficient;

                before->next = temp;
                temp->next = current;
                return;
            }

            before = current;
            current = current->next;
        }

        if(current->exponent < exponent)            //current placed at the last node
        {
            Node* temp = createNode();
            temp->exponent = exponent;
            temp->coefficient = coefficient;

            before->next = temp;
            temp->next = current;
        }
        else
        {
            Node* temp = createNode();
            temp->exponent = exponent;
            temp->coefficient = coefficient;

            current->next = temp;
        }
    }
}

void myPolynomial::deleteTerm(int exponent)
{
    if(!searchTerm(exponent))
        cout<<"Term with x^"<<exponent<<" is not found!"<<endl;
    else if(first->exponent == exponent)
    {
        Node* temp = first;
        first = first->next;

        cout<<"DELETED TERM: "<<temp->coefficient<<"x^"<<temp->exponent<<endl;

        delete temp;

    }
    else
    {
        Node* trav = first;

        while(trav != nullptr)
        {
            if(trav->next->exponent == exponent)
            {
                Node* temp = trav->next;
                trav->next = trav->next->next;


                cout<<"DELETED TERM: "<<temp->coefficient<<"x^"<<temp->exponent<<endl;
                delete temp;
                break;
            }
            trav = trav->next;
        }
    }
}

void myPolynomial::displayPoly()        //modified display
{                                       //does not show terms with coefficient 0 and
    if(first == nullptr)                //coefficient 1 is now shown
        cout<<"0"<<endl;
    else if(first->next == nullptr)
    {
        if(first->exponent == 0)
            cout<<first->coefficient<<endl;
        else
        {
            if(first->coefficient == 0)
                return;
            else if(first->coefficient == 1)
                cout<<"x^"<<first->exponent<<endl;
            else
                cout<<first->coefficient<<"x^"<<first->exponent<<endl;
        }
    }
    else
    {
        Node* trav = first;

        while(trav->next != nullptr)
        {
            if(trav->coefficient == 0)
            {
                trav = trav->next;
                continue;
            }
            if(trav->coefficient == 1)
                cout<<"x^"<<trav->exponent<<" + ";
            else
                cout<<"("<<trav->coefficient<<")x^"<<trav->exponent<<" + ";
            trav = trav->next;

            if(trav->next == nullptr)
            {
                if(trav->exponent == 0)
                    cout<<"("<<trav->coefficient<<")"<<endl;
                else
                {
                    if(trav->coefficient == 0)
                        return;
                    else if(trav->coefficient == 1)
                        cout<<"x^"<<trav->exponent<<endl;
                    else
                        cout<<"("<<trav->coefficient<<")"<<"x^"<<trav->exponent<<endl;
                }

            }
        }
    }
}

void myPolynomial::evalPoly(int x)
{
    if(first == nullptr)
        cout<<"0"<<endl;
    else
    {
        long long val{};

        Node* trav = first;
        while(trav != nullptr)
        {
            val += trav->coefficient * static_cast<long>(pow(x, trav->exponent));
            trav = trav->next;
        }

        cout<<val<<endl;
    }
}

Node* myPolynomial::searchTerm(int exponent) const
{
    Node* trav = first;

    while(trav != nullptr)
    {
        if(trav->exponent == exponent)
            return trav;
        trav = trav->next;
    }

    return nullptr;
}


myPolynomial myPolynomial::addPoly(const myPolynomial& P)
{
    myPolynomial sum(P);

    Node* trav = first;

    while(trav != nullptr)
    {
        sum.insertTerm(trav->coefficient, trav->exponent);
        trav = trav->next;
    }
    return sum;
}