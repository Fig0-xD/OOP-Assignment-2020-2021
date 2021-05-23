#include <iostream>
#include "myPolynomial.h"

using namespace std;

void func1()
{
    myPolynomial P;

    char choice{'N'};

    do
    {
        int coefficient{}, exponent{};
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial is as follows:\n";
    cout<<"P(x) = ";
    P.displayPoly();
    cout<<endl;
}

void func2()
{
    myPolynomial P1, P2;
    char choice{'N'};

    cout<<"Enter data for polynomial P1(x):\n";
    do
    {
        int coefficient{}, exponent{};
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P1.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial P1 is as follows:\n";
    cout<<"P1(x) = ";
    P1.displayPoly();
    cout<<endl;


    choice = 'N';
    cout<<"Enter data for polynomial P2(x):\n";
    do
    {
        int coefficient{}, exponent{};
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P2.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial P2 is as follows:\n";
    cout<<"P2(x) = ";
    P2.displayPoly();
    cout<<endl;


    myPolynomial sum{P1.addPoly(P2)};

    cout<<"P1(x) + P2(x) = ";
    sum.displayPoly();
    cout<<endl;
}

void func3()
{
    myPolynomial P;

    char choice{'N'};

    do
    {
        int coefficient{}, exponent{};
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial is as follows:\n";
    cout<<"P(x) = ";
    P.displayPoly();
    cout<<endl;

    int x{};
    cout<<"Enter the value of x:";    cin>>x;
    cout<<"P("<<x<<") = ";
    P.evalPoly(x);
    cout<<endl;
}

int main()
{
    while(true)
    {
        char choice{};
        cout << "\t\tMENU" << endl;
        cout << "1. Enter and display a polynomial\n2. Add two polynomials\n3. Evaluate a polynomial\n4. Quit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
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
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid input!!" << endl;
        }
    }
}