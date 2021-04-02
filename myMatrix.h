//
//Created by Fig0_xD on 13-02-2021.
//

#ifndef PROJ1_MYMATRIX_H
#define PROJ1_MYMATRIX_H


class myMatrix{

    int rows, columns;
    int **M;

    friend myMatrix multiplyMatrix(myMatrix A, myMatrix B);     // friend func to multiply matrix
    friend int detMatrix(int n,int **M);                        // friend func to find determinant of matrix

public:
    myMatrix();                     //non-parameterized constructor
    myMatrix(int, int);             //parameterized constructor
    int get_rows();                 // returns rows
    int get_columns();              // returns columns
    int** get_mat_ptr();            // returns pointer
    void alloc2DArray();            // allocates array
    void dealloc2DArray();          // deallocates array
    void read2DArray();             // read into the array
    void display2DArray();          // display the array
};

myMatrix multiplyMatrix(myMatrix A, myMatrix B);
int detMatrix(int n,int **M);

#endif //PROJ1_MYMATRIX_H
