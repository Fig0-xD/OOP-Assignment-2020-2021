#include <iostream>
#include "myQueue.h"
#include "myRand.h"

using namespace std;

void func1()
{
    cout<<endl<<"SINGLE OBJECT STATIC ALLOCATION"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the queue:";   cin>>size;

    myQueue Q(size);

    for(int i=0; i<size; i++)
        Q.enqueue(my_rand() % 100);

    cout<<"The queue is as follows:"<<endl;
    Q.display();

    for(int i=0; i<size; i++)
        Q.dequeue();

    cout<<"\n\n";
}

void func2()
{
    cout<<endl<<"SINGLE OBJECT DYNAMIC ALLOCATION"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the queue:";   cin>>size;

    myQueue* Q_ptr = new myQueue{size};

    for(int i=0; i<size; i++)
        Q_ptr->enqueue(my_rand() % 100);

    cout<<"The queue is as follows:"<<endl;
    Q_ptr->display();

    for(int i=0; i<size; i++)
        Q_ptr->dequeue();

    cout<<"\n\n";
}

void func3()
{
    cout<<endl<<"OBJECT ARRAY STATIC ALLOCATION:"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the queue array:";     cin>>size;

    myQueue Q[size];

    cout<<"An array of queues with queue size 5 each is created."<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for (int j=1; j<=5; j++)
            Q[i].enqueue(my_rand()%100);
        cout<<endl;
    }

    cout<<endl<<"The queue array is as follows:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<endl;
        Q[i].display();
        cout<<endl;
    }

    cout<<endl<<"Dequeuing the queue:"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for(int j=1; j<=5; j++)
            Q[i].dequeue();
        cout<<endl;
    }

    cout<<"\n\n";
}

void func4()
{
    cout<<endl<<"OBJECT ARRAY STATIC ALLOCATION:"<<endl<<endl;

    int size{};
    cout<<"Enter the size of the queue array:";     cin>>size;

    myQueue* Q_ptr = new myQueue[size];

    cout<<"An array of queues with queue size 5 each is created."<<endl;
    
    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for (int j=1; j<=5; j++)
            Q_ptr[i].enqueue(my_rand() % 100);
        cout<<endl;
    }

    cout<<endl<<"The queue array is as follows:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<endl;
        Q_ptr[i].display();
        cout<<endl;
    }

    cout<<endl<<"Dequeuing the queue:"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<"S - "<<i+1<<":"<<endl;
        for(int j=1; j<=5; j++)
            Q_ptr[i].dequeue();
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