#include <iostream>
#include <iomanip>
#include "myMatrix.h"

using namespace std;

int main()
{
    myMatrix data[6];           // declaring a array of object myMatrix of size 6

    int count{1};
    for(auto& obj: data)
    {
        int size;
        cout<<"Number of students in Dept. ["<<count++<<"] :";
        cin>>size;
        obj.alloc2DArray(size);
        cout<<endl;
    }

    for(auto& obj: data)
        obj.read2DArray();

    count = 1;
    float batch_topper_marks{0.00};
    int batch_topper_dept{}, batch_topper_position{};

    cout<<setw(15)<<"DEPARTMENT"<<setw(14)<<"TOPPER MARKS"<<setw(13)<<"ROLL NUMBER"<<endl;
    cout<<setw(43)<<"---------------------------------------"<<endl;

    for(auto& obj: data)
    {
        obj.deptTopper();
        if(obj.getTopperMarks()>batch_topper_marks)             // Obtaining the topper from the whole batch
        {
            batch_topper_dept = count;
            batch_topper_marks = obj.getTopperMarks();
            batch_topper_position = obj.getTopperPosition();
        }

        cout<<setw(10)<<"["<<count++<<"]"<<setw(13)<<fixed<<setprecision(2)<<obj.getTopperMarks()<<setw(11);
        cout<<"["<<obj.getTopperPosition() + 1<<"]"<<endl;
    }

    cout<<endl<<endl<<setw(29)<<"BATCH TOPPER"<<endl;
    cout<<setw(15)<<"DEPARTMENT"<<setw(14)<<"TOPPER MARKS"<<setw(13)<<"ROLL NUMBER"<<endl;
    cout<<setw(43)<<"---------------------------------------"<<endl;
    cout<<setw(10)<<"["<<batch_topper_dept<<"]"<<setw(13)<<fixed<<setprecision(2)<<batch_topper_marks<<setw(11);
    cout<<"["<<batch_topper_position + 1<<"]"<<endl;


    for(auto& obj: data)
        obj.dealloc2DArray();

    return 0;
}
