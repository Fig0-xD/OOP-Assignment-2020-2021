//
// Created by SUBHADEEP DUTTA on 23-02-2021.
//

#ifndef PROJ1_MYMATRIX_H
#define PROJ1_MYMATRIX_H


class myMatrix{

    int rows, columns;
    int **M;

    friend myMatrix multiplyMatrix(const myMatrix& A, const myMatrix& B);     // friend func to multiply matrices
    friend myMatrix addMatrix(const myMatrix& A, const myMatrix& B);          // friend func to add matrices
    friend int detMatrix(int order,int **M);                        // friend func to find determinant of matrix
    friend void cramerSolve(const myMatrix &A, const myMatrix &C);  // friend func to solve linear equations

public:
    myMatrix();                     // non-parameterized constructor
    myMatrix(int, int);             // parameterized constructor
    myMatrix(const myMatrix &obj);  // Copy constructor for deep copying
    ~myMatrix();                    // destructor to deallocate array
    int get_rows();                 // returns rows
    int get_columns();              // returns columns
    int** get_mat_ptr();            // returns pointer
    void allocateSpace();           // allocates array
    void readMatrix();              // read into the array
    void displayMatrix() const;           // display the array
};

myMatrix multiplyMatrix(const myMatrix& A, const myMatrix& B);
myMatrix addMatrix(const myMatrix& A, const myMatrix& B);
int detMatrix(int order,int **M);
void cramerSolve(const myMatrix &A, const myMatrix &C);


#endif //PROJ1_MYMATRIX_H
