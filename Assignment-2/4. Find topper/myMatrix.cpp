#include "myMatrix.h"
#include "myRand.h"

using namespace std;


void myMatrix::alloc2DArray(int s)
{
    size = s;
    M = new float[s];
}

void myMatrix::dealloc2DArray()
{
    delete[] M;
}

void myMatrix::read2DArray()
{
    for(int i=0; i<size; i++)
    {
        float val = (my_rand() % 1001) * 0.01;
        if(val >= 5.00)
            M[i] = val;
        else
            i--;
    }
}

void myMatrix::deptTopper()
{
    float max{0.00};
    int pos{};
    for(int i=0; i<size; i++)
    {
        if(M[i] > max) {
            max = M[i];
            pos = i;
        }
    }
    topper_marks = max;
    topper_position = pos;
}

float myMatrix::getTopperMarks()
{
    return topper_marks;
}

int myMatrix::getTopperPosition()
{
    return topper_position;
}
