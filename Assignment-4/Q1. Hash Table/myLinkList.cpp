//
// Created by SUBHADEEP DUTTA on 28-02-2021.
//
#include <iostream>
#include "myLinkList.h"

using namespace std;

myLinkList::myLinkList(): first{nullptr} {}

myLinkList::~myLinkList()
{
    node* current = first;
    node* next = nullptr;
    while(current!= nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    first = nullptr;
}

node* myLinkList::createNode()
{
    node* ptr = new node;
    ptr->data = 0;
    ptr->next = nullptr;
    return ptr;
}

void myLinkList::display()
{
    node* trav = first;
    cout<<"[ ";
    while(trav!= nullptr)
    {
        cout<<trav->data<<" -> ";
        trav = trav->next;
    }
    cout<<"NULL ]"<<endl;
}

void myLinkList::insertBeg(int item)
{
    if(first == nullptr)
    {
        node* temp = createNode();
        temp->data = item;
        first = temp;
    }
    else
    {
        node* temp = createNode();
        temp->data = item;
        temp->next = first;
        first = temp;
    }
}

bool myLinkList::search(int element)
{
    if(first == nullptr)
        return false;
    else
    {
        node* trav = first;

        while(trav!= nullptr)
        {
            if(trav->data == element)
                return true;
            trav = trav->next;
        }

        return false;
    }
}

void myLinkList::del(int element)
{
    if(search(element))
    {
        node* trav = first;

        if(trav->data == element)
        {
            first = first->next;
            delete trav;
            cout<<"The element -> "<<element<<" is successfully deleted"<<endl;
        }
        else
        {
            while(trav != nullptr)
            {
                if(trav->next->data == element)
                {
                    node* temp = trav->next;
                    trav->next = trav->next->next;

                    delete temp;
                    break;
                }
                trav = trav->next;
            }
            cout<<"The element -> "<<element<<" is successfully deleted"<<endl;
        }
    }
}

int myLinkList::countNodes()
{
    node* trav = first;
    int count{};
    while(trav != nullptr)
    {
        count++;
        trav = trav->next;
    }
    return count;
}
