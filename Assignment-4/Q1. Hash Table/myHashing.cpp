//
// Created by SUBHADEEP DUTTA on 09-03-2021.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "myHashing.h"


using namespace std;
const double a = 0.618033;

myHashing::myHashing(): myHashing(5) {}
myHashing::myHashing(int s)
{
    size = s;
    ptr = new myLinkList[size];
}

myHashing::~myHashing()
{
    for(int i=0; i<size; i++)
        ptr[i].~myLinkList();

    delete[] ptr;
}

int myHashing::hashFunc(int val)
{
    return val%10;
}

int myHashing::myhashFunc(int val)
{
    return floor(size*(fmod((val * a), 1)));
}

void myHashing::insert(int val)
{
    ptr[hashFunc(val)].insertBeg(val);
}

void myHashing::myinsert(int val)
{
    ptr[myhashFunc(val)].insertBeg(val);
}

bool myHashing::search(int val)
{
    return ptr[hashFunc(val)].search(val);
}

bool myHashing::mysearch(int val)
{
    return ptr[myhashFunc(val)].search(val);
}

void myHashing::del(int val)
{
    if(search(val))
    {
        ptr[hashFunc(val)].del(val);
        cout<<"Successful delete!"<<endl;
    }
    else
        cout<<"No element found to delete"<<endl;
}

void myHashing::mydel(int val)
{
    if(mysearch(val))
    {
        ptr[myhashFunc(val)].del(val);
        cout<<"Successful delete!"<<endl;
    }
    else
        cout<<"No element found to delete"<<endl;
}
void myHashing::display()
{
    for(int i=0; i<size; i++)
        ptr[i].display();
}

double myHashing::TableLoadDistribution()
{
    double chi{};
    for(int i=0; i<10; i++)
    {
        double load = static_cast<double>(ptr[i].countNodes()) / 100;
        cout << "Bucket[" << i + 1 << "] = " << fixed << setprecision(1) << load * 100 << "%" << endl;

        chi += pow(load - 0.1, 2)/0.1;
    }

    return chi;
}
