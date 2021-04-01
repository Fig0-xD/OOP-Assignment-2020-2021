#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n{};
    cout<<"Enter a number:";
    cin>>n;

    cout<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        int t = i+1;
        cout << setw(i+1);
        for (int j = 1; j <= n-i; j++) {
            cout << t++;
        }
        for(int j = n-1; j > i; j--){
            cout<<j;
        }
        cout<<endl;
    }

    for(int i=n-1; i>0; i--)
    {
        int t = n-1;
        cout << setw(i);
        for(int j = i; j <= n; j++) {
            cout << j;
        }
        for(int j = 0; j < n-i; j++){
            cout << t--;
        }
        cout<<endl;
    }

    return 0;
}