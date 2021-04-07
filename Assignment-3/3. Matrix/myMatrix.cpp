//
// Created by SUBHADEEP DUTTA on 23-02-2021.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include "myMatrix.h"

using namespace std;

myMatrix::myMatrix()
{
    int m, n;
    cout<<"Enter number of rows:";  cin>>m;
    cout<<"Enter number of columns:";   cin>>n;

    rows = m;
    columns = n;

    allocateSpace();
}
myMatrix::myMatrix(int m, int n): rows{m}, columns{n}
{
    allocateSpace();
}

myMatrix::myMatrix(const myMatrix &obj) : myMatrix(obj.rows, obj.columns)   // Use of delegating constructor
{
    for(int i=0; i<obj.rows; i++)
        for(int j=0; j<obj.columns; j++)
            M[i][j] = *(*(obj.M + i) + j);

}

myMatrix::~myMatrix()
{
    for(int i=0; i<rows; i++)
        delete[] M[i];

    delete[] M;
}

int myMatrix::get_rows() {  return rows; }
int myMatrix::get_columns() {   return columns; }
int** myMatrix::get_mat_ptr() { return M; }
void myMatrix::allocateSpace()
{
    M = new int*[rows];

    for(int i=0; i<rows; i++)
        M[i] = new int[columns];
}

void myMatrix::readMatrix()
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            cin>>M[i][j];
}

void myMatrix::displayMatrix() const
{
    for(int i=0; i<rows; i++)
    {   cout<<"[ ";
        for(int j=0; j<columns; j++)
            cout<<M[i][j]<<" ";
        cout<<"]"<<endl;
    }
}


myMatrix addMatrix(const myMatrix& A, const myMatrix& B)
{
    myMatrix Sum(A.rows, A.columns);

    for(int i=0; i<A.rows; i++)
        for(int j=0; j<A.columns; j++)
            *(*(Sum.M + i) + j) = *(*(A.M + i) + j) + *(*(B.M + i) + j);

    return Sum;
}


myMatrix multiplyMatrix(const myMatrix& A, const myMatrix& B)
{

    myMatrix res(A.rows, B.columns);

    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < B.columns; j++)
        {
            *(*(res.M + i) + j) = 0;
            for (int k = 0; k < A.columns; k++)
            {
                *(*(res.M + i) + j) += *(*(A.M + i) + k) * *(*(B.M + k) + j);
            }
        }
    }

    return res;
}


int detMatrix(int order,int **M)
{
    if(order==2)                                //returns determinant val when order is 2
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
            det += int( pow(-1,col_M))*M[0][col_M]* (detMatrix(order-1,temp));  //determinant value gets incremented
        }

        return det;
    }

}

void cramerSolve(const myMatrix &A, const myMatrix &C)
{

    cout<<"Coefficient Matrix (A): "<<endl;
    A.displayMatrix();                   // Displaying the coefficient matrix (A)
    cout<<endl;

    cout<<"Constant Matrix (C): "<<endl;
    C.displayMatrix();                // Displaying the numerator matrix
    cout<<endl;


    int D_A = detMatrix(A.rows, A.M);

    myMatrix D_A_i(1, C.rows);
    int count{};


    for(int i=0; i<A.rows; i++)
    {
        myMatrix D_i(A);
        for(int j=0; j<A.rows; j++)
        {
            *(*(D_i.M + j) + i ) = *(*(C.M + j) + 0 );
        }
        *(*(D_A_i.M + 0)+count) = detMatrix(D_i.rows,D_i.M) ;     // Reading into D_x_i matrix
        count++;

    }


    if(D_A==0)                // Checking for inconsistent and indeterminate conditions
    {
        bool flag{true};

        for(int i=1; i<count; i++)
            if(*(*(D_A_i.M + 0)+0) != *(*(D_A_i.M + 0)+i))
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
            cout << "x_" << i+1 << " = " << static_cast<float>( *(*(D_A_i.M + 0)+i) )/ static_cast<float>( D_A ) << endl;
    }

}