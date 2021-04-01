#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

const double pi = 3.14159;

void cos_func()
{
    cout<<"Enter the bounds of the graph in degrees"<<endl;
    double lower{}, upper{};
    int step{};
    char c{};
    cout<<"Lower Bound:";       cin>>lower;
    cout<<"Upper Bound:";       cin>>upper;
    cout<<"Enter the step length:";     cin>>step;
    cout<<"Enter the fill character:";  cin>>c;

    cout<<endl<<endl;


    double i = lower, interval = (upper - lower)/step;

    while(i <= upper)
    {
        int val = floor(cos((i*pi)/180) * 50);

        if(val>=0)
        {
            cout <<setw(60) << setfill(' ') << "||" << setw(val) << setfill(c) << '*' << endl;
        }
        else
        {
            val=abs(val);
            cout <<setw(60-val) << setfill(' ') << '*' << setw(val) << setfill(c) << "||" << endl ;
        }

        i = i + interval;
    }
}


void exp_func()
{
    cout<<"Enter the bounds of the graph:"<<endl;
    double lower{}, upper{};
    cout<<"Lower bound:";   cin>>lower;
    cout<<"Upper bound:";   cin>>upper;

    int step{};
    cout<<"Enter the step length:";     cin>>step;

    char c{};
    cout<<"Enter the fill character:";  cin>>c;

    cout<<endl;

    double i = lower, interval = (upper - lower)/step;

    while(i <= upper)
    {
        double val = exp(i);

        if(val<1)
        {
            cout <<setw(5) << setfill(' ') << "||" << setw(int (val*10)) << setfill(c) << "*" << endl;
        }
        else
        {
            cout <<setw(5) << setfill(' ') << "||" << setw(int(val*12)) << setfill(c) << "*" << endl;
        }

        i = i + interval;
    }

}

int main()
{
    char choice{};
    while(true) {
        cout << "Which function do you want to use?\n1. Cosine Function\n2. Exponential Function" << endl;
        cout << "Enter choice (1/2):";
        cin >> choice;

        switch (choice) {
            case '1':
                cos_func();
                break;
            case '2':
                exp_func();
                break;
            default: cout<<"Oops! Something wrong happened"<<endl;
        }

        cout << "Do you want to repeat again?(Y/N):";
        cin >> choice;

        if(choice=='N' || choice=='n')
            break;
    }

    cout<<endl<<"Program closing...."<<endl;
    return 0;
}