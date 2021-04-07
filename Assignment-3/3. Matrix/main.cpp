#include <iostream>
#include "myMatrix.h"

using namespace std;

int main()
{
    while (true)
    {
        char choice;
        cout << "\t\t MENU" << endl;
        cout << "1. Allocate a matrix, read values and display it" << endl;
        cout << "2. Read values in two matrices and add both matrices" << endl;
        cout << "3. Read values in two matrices and multiply both matrices" << endl;
        cout << "4. Finding determinant of a matrix" << endl;
        cout << "5. Solving linear equation using Cramer's Rule" <<endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice:";
        cin >> choice;


        switch (choice) {
            case '1': {
                cout << "Allocating a matrix..." << endl;
                myMatrix M;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                M.readMatrix();
                cout << "The matrix is as follows:" << endl;
                M.displayMatrix();
            }
                break;
            case '2' : {
                cout << "Allocating matrix A" << endl;
                myMatrix A;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                A.readMatrix();
                cout << "The matrix is as follows:" << endl;
                A.displayMatrix();


                cout << endl << "Allocating matrix B" << endl;
                myMatrix B;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                B.readMatrix();
                cout << "The matrix is as follows:" << endl;
                B.displayMatrix();

                if (A.get_columns() != B.get_columns() or A.get_rows() != A.get_rows())
                    cout << "Matrix addition not possible" << endl << endl;
                else {
                    myMatrix res(addMatrix(A, B));
                    cout << "Mat(A) + Mat(B):" << endl;
                    res.displayMatrix();
                    cout << endl;
                }
            }
                break;
            case '3': {
                cout << "Allocating matrix A" << endl;
                myMatrix A;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                A.readMatrix();
                cout << "The matrix is as follows:" << endl;
                A.displayMatrix();


                cout << endl << "Allocating matrix B" << endl;
                myMatrix B;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                B.readMatrix();
                cout << "The matrix is as follows:" << endl;
                B.displayMatrix();

                if (A.get_columns() != B.get_rows())
                    cout << "Matrix multiplication not possible" << endl << endl;
                else {
                    myMatrix res(multiplyMatrix(A, B));
                    cout << "Mat(A) * Mat(B):" << endl;
                    res.displayMatrix();
                    cout << endl;
                }
            }
                break;
            case '4': {
                cout << "Allocating a matrix..." << endl;
                myMatrix M;
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                M.readMatrix();
                cout << "The matrix is as follows:" << endl;
                M.displayMatrix();

                if (M.get_rows() != M.get_columns())
                    cout << "Determinant not possible as rows is not equal to columns" << endl << endl;
                else
                    cout << "Det(M) = " << detMatrix(M.get_rows(),M.get_mat_ptr()) << endl << endl;
            }
                break;
            case '5': {
                int variables{};
                cout<<"Enter the number of variables:";     cin>>variables;
                myMatrix A(variables, variables), C(variables, 1);
                cout<<"Enter the coefficient matrix (A):"<<endl;
                A.readMatrix();
                cout<<"Enter the constant matrix (C):"<<endl;
                C.readMatrix();
                cramerSolve(A, C);
            }
                break;
            case '6' : {
                cout << "Exiting program.." << endl;
                return 0;
            }
            default:
                cout << "Invalid input" << endl << endl;
        }
    }
}
