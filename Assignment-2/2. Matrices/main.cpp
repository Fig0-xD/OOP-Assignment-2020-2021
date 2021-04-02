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
        cout << "2. Read values in two matrices and multiply both matrices" << endl;
        cout << "3. Finding determinant of a matrix" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter choice:";
        cin >> choice;


        switch (choice) {
            case '1': {
                myMatrix M;
                cout << "Allocating a matrix..." << endl;
                M.alloc2DArray();
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                M.read2DArray();
                cout << "The matrix is as follows:" << endl;
                M.display2DArray();

                M.dealloc2DArray();
            }
                break;
            case '2': {
                myMatrix A, B, res;
                cout << "Allocating matrix A" << endl;
                A.alloc2DArray();
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                A.read2DArray();
                cout << "The matrix is as follows:" << endl;
                A.display2DArray();


                cout << endl << "Allocating matrix B" << endl;
                B.alloc2DArray();
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                B.read2DArray();
                cout << "The matrix is as follows:" << endl;
                B.display2DArray();

                if (A.get_columns() != B.get_rows())
                    cout << "Matrix multiplication not possible" << endl << endl;
                else {
                    res = multiplyMatrix(A, B);
                    cout << "Mat(A) * Mat(B):" << endl;
                    res.display2DArray();
                    cout << endl;
                }

                A.dealloc2DArray();
                B.dealloc2DArray();
                res.dealloc2DArray();
            }
                break;
            case '3': {
                myMatrix M;
                cout << "Allocating a matrix..." << endl;
                M.alloc2DArray();
                cout << "Matrix allocated" << endl;
                cout << "Enter values for the matrix:" << endl;
                M.read2DArray();
                cout << "The matrix is as follows:" << endl;
                M.display2DArray();

                if (M.get_rows() != M.get_columns())
                    cout << "Determinant not possible as rows is not equal to columns" << endl << endl;
                else
                    cout << "Det(M) = " << detMatrix(M.get_rows(),M.get_mat_ptr()) << endl << endl;

                M.dealloc2DArray();
            }
                break;
            case '4' : {
                cout << "Exiting program.." << endl;
                return 0;
            }
            default:
                cout << "Invalid input" << endl << endl;
        }
    }
}
