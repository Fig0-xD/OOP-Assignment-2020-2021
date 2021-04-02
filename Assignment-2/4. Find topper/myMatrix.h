#ifndef PROJ1_MYMATRIX_H
#define PROJ1_MYMATRIX_H


class myMatrix{

    int size, topper_position;
    float *M;
    float topper_marks;

public:
    void alloc2DArray(int);     // Allocation of the array
    void dealloc2DArray();      // Deallocation
    void read2DArray();         // Reading into the array using random numbers
    void deptTopper();          // Finding the topper
    float getTopperMarks();     // Returns topper_marks
    int getTopperPosition();    // Returns topper_position
};



#endif //PROJ1_MYMATRIX_H
