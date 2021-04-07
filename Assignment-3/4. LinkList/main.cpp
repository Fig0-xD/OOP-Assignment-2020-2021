#include <iostream>
#include "myLinkList.h"
#include "myRand.h"

using namespace std;

void func1()
{
    cout<<endl<<"SINGLE OBJECT STATIC ALLOCATION"<<endl<<endl;
    myLinkList L;

    int n{};
    cout<<"Enter number of inputs:";    cin>>n;

    int n1 = n;
    while(n1--)
        L.insertBeg(my_rand()%10);

    cout<<"Linklist L: "<<endl;
    L.display();

    cout<<endl<<"Deletion in progress:"<<endl;
    while(n--)
        L.del(my_rand()%10);

    cout<<endl<<"After deletion in linklist L:"<<endl;
    L.display();


    cout<<endl<<"CONCATENATE 2 LINKLISTS:"<<endl;
    myLinkList L1, L2;

    cout<<"Enter number of elements in linklist L1: ";  cin>>n;
    while(n--)
        L1.insertBeg(my_rand()%100);

    cout<<"L1:"<<endl;
    L1.display();


    cout<<endl<<"Enter number of elements in linklist L2: ";  cin>>n;
    while(n--)
        L2.insertBeg(my_rand()%100);

    cout<<"L2:"<<endl;
    L2.display();

    cout<<endl<<"Concatenating L2 to L1:"<<endl;
    L1.concatenate(L2);

    L1.display();
    cout<<"\n\n";
}

void func2()
{
    cout<<endl<<"SINGLE OBJECT DYNAMIC ALLOCATION"<<endl<<endl;
    myLinkList* L_ptr = new myLinkList;

    int n{};
    cout<<"Enter number of inputs:";    cin>>n;

    int n1 = n;
    while(n1--)
        L_ptr -> insertBeg(my_rand() % 10);

    cout<<"Linklist L: "<<endl;
    L_ptr -> display();

    cout<<endl<<"Deletion in progress:"<<endl;
    while(n--)
        L_ptr -> del(my_rand() % 10);

    cout<<endl<<"After deletion in linklist L:"<<endl;
    L_ptr -> display();


    cout<<endl<<"CONCATENATE 2 LINKLISTS:"<<endl;
    myLinkList* L1_ptr = new myLinkList;
    myLinkList* L2_ptr = new myLinkList;

    cout<<"Enter number of elements in linklist L1: ";  cin>>n;
    while(n--)
        L1_ptr -> insertBeg(my_rand() % 100);

    cout<<"L1:"<<endl;
    L1_ptr -> display();


    cout<<endl<<"Enter number of elements in linklist L2: ";  cin>>n;
    while(n--)
        L2_ptr -> insertBeg(my_rand() % 100);

    cout<<"L2:"<<endl;
    L2_ptr -> display();

    cout<<endl<<"Concatenating L2 to L1:"<<endl;
    L1_ptr -> concatenate(L2_ptr);

    L1_ptr -> display();
    cout<<"\n\n";
}

void func3()
{
    cout<<endl<<"OBJECT ARRAY STATIC ALLOCATION"<<endl<<endl;
    int size{};
    cout<<"Enter the size of the linklist array:";    cin>>size;

    myLinkList L[size];

    for(int i=0; i<size; i++)
    {
        int n = my_rand()%10;
        while(n--)
            L[i].insertBeg(my_rand()%10);
    }

    cout<<"The array of linklist is:"<<endl;

    for(int i=0; i<size; i++)
        L[i].display();

    cout<<endl<<"CONCATENATE THE FIRST WITH THE REMAINING LINKLISTS:"<<endl;

    for(int i=1; i<size; i++)
        L[0].concatenate(L[i]);

    cout<<"Final result after concatenation:"<<endl;
    L[0].display();
    cout<<"\n\n";
}

void func4()
{
    cout<<endl<<"OBJECT ARRAY DYNAMIC ALLOCATION"<<endl<<endl;
    int size{};
    cout<<"Enter the size of the linklist array:";    cin>>size;

    myLinkList* L_ptr = new myLinkList[size];

    for(int i=0; i<size; i++)
    {
        int n = my_rand()%10;
        while(n--)
            L_ptr[i].insertBeg(my_rand() % 10);
    }

    cout<<"The array of linklist is:"<<endl;

    for(int i=0; i<size; i++)
        L_ptr[i].display();

    cout<<endl<<"CONCATENATE THE FIRST WITH THE REMAINING LINKLISTS:"<<endl;

    for(int i=1; i<size; i++)
        L_ptr[0].concatenate(L_ptr[i]);

    cout<<"Final result after concatenation:"<<endl;
    L_ptr[0].display();
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
