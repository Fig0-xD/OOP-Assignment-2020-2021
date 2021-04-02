#include <iostream>
#include <cmath>
#include <algorithm>
#include "myMatrix.h"
#include "myRand.h"

using namespace std;
myMatrix::myMatrix():M(nullptr), rows(0), columns(0) {}
myMatrix::myMatrix(int m, int n)
{
    rows = m;
    columns = n;

    M = new int*[rows];

    for(int i=0; i<rows; i++)
        M[i] = new int[columns];
}

myMatrix::myMatrix(const myMatrix &obj) : myMatrix(obj.rows, obj.columns)   // USe of delegating constructor
{
    for(int i=0; i<obj.rows; i++)
        for(int j=0; j<obj.columns; j++)
            M[i][j] = *(*(obj.M + i) + j);

}

void myMatrix::dealloc2DArray()
{
    for(int i=0; i<rows; i++)
        delete[] M[i];

    delete[] M;
}

void myMatrix::read2DArray()
{
    cout<<"The coefficients are filled randomly."<<endl<<endl;
    for(int i=0; i<rows; i++)
    {
        for (int j = 0; j < columns; j++)
            M[i][j] = my_rand() % 100;
    }
}

void myMatrix::print2DArray()
{
    for(int i=0; i<rows; i++)
    {
        cout<<"[ ";
        for(int j=0; j<columns; j++)
            cout<<M[i][j]<<" ";
        cout<<"]"<<endl;
    }
}

void myMatrix::solve()
{
    myMatrix D(rows, rows), D_c(rows,1);

    for(int i=0; i<rows; i++)
        for(int j=0; j<rows; j++)
            *(*(D.M + i) + j ) =  M[i][j];

    for(int i=0; i<rows; i++)
        *(*(D_c.M + i) + 0) = M[i][columns - 1];

    cout<<"Constant Matrix : "<<endl;
    D_c.print2DArray();                 // Displaying the numerator matrix
    cout<<endl;

    D_c.dealloc2DArray();

    cout<<"Coefficient Matrix (D): "<<endl;
    D.print2DArray();                   // Displaying the coefficient matrix (D)
    cout<<endl;

    int D_val = detMatrix(D.rows, D.M);

    myMatrix D_i_val(1, rows);
    int count{};


    for(int i=0; i<rows; i++)
    {
        myMatrix D_i(D);
        for(int j=0; j<rows; j++)
        {
            *(*(D_i.M + j) + i ) = M[j][columns - 1];
        }
        *(*(D_i_val.M + 0)+count) = detMatrix(D_i.rows,D_i.M) ;     // Reading into D_x_i matrix
        count++;

        D_i.dealloc2DArray();
    }


    if(D_val==0)                // Checking for inconsistent and indeterminate conditions
    {
        bool flag{true};

        for(int i=1; i<count; i++)
            if(*(*(D_i_val.M + 0)+0) != *(*(D_i_val.M + 0)+i))
            {
                flag = false;
                break;
            }

        if(flag)
            cout<<endl<<"Indeterminate equations => Infinitely many solutions"<<endl;
        else
            cout<<endl<<"Inconsistent equations => No solutions"<<endl;
    }
    else
    {
        cout<<endl<<"Consistent equations => Only one solution"<<endl;
        cout<<"The solutions is as follows:"<<endl;

        for(int i=0; i<count; i++)
            cout << "x_" << i+1 << " = " << static_cast<float>( *(*(D_i_val.M + 0)+i) )/ static_cast<float>( D_val ) << endl;
    }

    D_i_val.dealloc2DArray();
    D.dealloc2DArray();
}


int detMatrix(int order,int **M)
{
    if(order==2)
    {
        return M[0][0]*M[1][1]-M[0][1]*M[1][0];
    }
    else
    {
        int det{};
        for(int col_M=0; col_M<order; col_M++)
        {
            int **temp = new int *[order-1];
            for(int i=0; i<order-1; i++)
            {
                temp[i]=new int[order-1];
            }
            for(int row_M=1; row_M<order; row_M++)
            {
                int col_temp{};
                int row_temp{row_M-1};
                for(int j=0; j<order; j++)
                {
                    if(col_M!=j)
                    {
                        temp[row_temp][col_temp]=M[row_M][j];
                        col_temp++;
                    }
                }
                row_temp++;
            }
            det += int( pow(-1,col_M))*M[0][col_M]* (detMatrix(order-1,temp));
        }
        return det;
    }
}