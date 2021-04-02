#include <iostream>
#include <chrono>
#include "myMatrix.h"

using namespace std;

int main()
{
    auto start = std::chrono::system_clock::now();

    int n;
    cout<<"Enter the number of variables:";     cin>>n;

    myMatrix main(n, n+1);              // Creating a matrix to hold coefficients of variables and the constant
    main.read2DArray();                 // Reading in the matrix

    main.solve();                       // Applying cramer's rule

    main.dealloc2DArray();              // Finally matrix is deallocated


    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(end - start);
    cout<<"EXECUTION TIME:"<<duration.count()<<" secs"<<endl;

    return 0;
}