#include <iostream>
#include "myStack.h"
#include "myRand.h"

using namespace std;

void func1()
{
    cout<<endl<<"SINGLE OBJECT STATIC ALLOCATION"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the stack:";   cin>>size;

    myStack s(size);

    for(int i=0; i<size; i++)
        s.push(my_rand()%100);

    cout<<"The stack is as follows:"<<endl;
    s.display();

    for(int i=0; i<size; i++)
        s.pop();

    cout<<"\n\n";
}

void func2()
{
    cout<<endl<<"SINGLE OBJECT DYNAMIC ALLOCATION"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the stack:";   cin>>size;

    myStack* s_ptr = new myStack{size};

    for(int i=0; i<size; i++)
        s_ptr->push(my_rand()%100);

    cout<<"The stack is as follows:"<<endl;
    s_ptr->display();

    for(int i=0; i<size; i++)
        s_ptr->pop();

    cout<<"\n\n";
}

void func3()
{
    cout<<endl<<"OBJECT ARRAY STATIC ALLOCATION:"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the stack array:";     cin>>size;

    myStack s[size];

    cout<<"An array of stacks with stack size 5 each is created."<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for (int j=1; j<=5; j++)
            s[i].push(my_rand()%100);
        cout<<endl;
    }

    cout<<endl<<"The stack array is as follows:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<endl;
        s[i].display();
        cout<<endl;
    }

    cout<<endl<<"Popping the stack:"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for(int j=1; j<=5; j++)
            s[i].pop();
        cout<<endl;
    }

    cout<<"\n\n";
}

void func4()
{
    cout<<endl<<"OBJECT ARRAY DYNAMIC ALLOCATION:"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the stack array:";     cin>>size;

    myStack* s_ptr = new myStack[size];

    cout<<"An array of stacks with stack size 5 each is created."<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for (int j=1; j<=5; j++)
            s_ptr[i].push(my_rand() % 100);
        cout<<endl;
    }

    cout<<endl<<"The stack array is as follows:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<endl;
        s_ptr[i].display();
        cout<<endl;
    }

    cout<<endl<<"Popping the stack:"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for(int j=1; j<=5; j++)
            s_ptr[i].pop();
        cout<<endl;
    }

    cout<<"\n\n";
}


int main()
{
    while(true)
    {
        char choice{};
        cout << "\t\tMENU" << endl;
        cout<< "1. SINGLE OBJECT STATIC ALLOCATION\n2. SINGLE OBJECT DYNAMIC ALLOCATION";
        cout<<"\n3. OBJECT ARRAY STATIC ALLOCATION\n4. OBJECT ARRAY DYNAMIC ALLOCATION\n5. QUIT\n";
        cout << "Enter choice:";
        cin >> choice;

        switch (choice)
        {
            case '1':
                func1();
                break;

            case '2':
                func2();
                break;

            case '3':
                func3();
                break;

            case '4':
                func4();
                break;

            case '5': {
                cout << "EXITING PROGRAM.." << endl;
                return 0;
            }

            default:
                cout << "Wrong input, renter again!" << endl << endl;
        }
    }
}