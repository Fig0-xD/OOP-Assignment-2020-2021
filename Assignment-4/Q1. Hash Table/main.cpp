#include <iostream>
#include <iomanip>
#include "myHashing.h"
#include "myRand.h"

using namespace std;

int main()
{
    myHashing H1(10), H2(10);
    for(int i=0; i<100; i++)
    {
        int element = my_rand()%100;
        H1.insert(element);
        H2.myinsert(element);
    }

    cout<<"Load distribution of HashTable 1:\n";
    double chi1 = H1.TableLoadDistribution();
    cout << endl << "Chi-square test: " << fixed << setprecision(3) << chi1 << endl << endl;
    cout<<"\nLoad distribution of HashTable 2:\n";
    double chi2 = H2.TableLoadDistribution();
    cout << endl << "Chi-square test: " << fixed << setprecision(3) << chi2 << endl << endl;


    if(chi1 < chi2)
        cout << "Here MODULAR METHOD is more efficient" << endl;
    else
        cout << "Here MULTIPLICATIVE METHOD is more efficient" << endl;
    return 0;
}
