//
//Created by Fig0_xD on 13-02-2021
//

#ifndef PROJ1_MYMATRIX_H
#define PROJ1_MYMATRIX_H


class myMatrix{

    int rows, columns;
    int **M;
    friend int detMatrix(int n,int **M);
public:
    myMatrix();                     // Non-parameterized constructor
    myMatrix(int, int);             // Parameterized constructor
    myMatrix(const myMatrix &obj);  // Copy constructor for deep copying
    void dealloc2DArray();          // Deallocation of pointer in the object
    void read2DArray();             // Reading in matrix
    void print2DArray();            // Displaying the matrix
    void solve();                   // Solving the linear equations using Cramer's Rule
};

int detMatrix(int n,int **M);       // Determinant of matrix

#endif //PROJ1_MYMATRIX_H
