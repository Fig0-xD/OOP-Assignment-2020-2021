#include <iostream>
#include <cmath>
#include <algorithm>
#include "myMatrix.h"

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

int myMatrix::get_rows() {  return rows; }
int myMatrix::get_columns() {   return columns; }
int** myMatrix::get_mat_ptr() { return M; }
void myMatrix::alloc2DArray()
{
    int n, m;

    cout<<"No. of rows:";   cin>>n;
    cout<<"No. of columns:";    cin>>m;

    rows = n;
    columns = m;

    M = new int*[n];

    for(int i=0; i<n; i++)
        M[i] = new int[m];
}

void myMatrix::dealloc2DArray()
{
    for(int i=0; i<rows; i++)
        delete[] M[i];

    delete[] M;
}

void myMatrix::read2DArray()
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            cin>>M[i][j];
}

void myMatrix::display2DArray()
{
    for(int i=0; i<rows; i++)
    {   cout<<"[ ";
        for(int j=0; j<columns; j++)
            cout<<M[i][j]<<" ";
        cout<<"]"<<endl;
    }
}

myMatrix multiplyMatrix(myMatrix A, myMatrix B)
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