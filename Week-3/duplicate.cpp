#include <iostream>
using namespace std;
#include <algorithm>

bool has_duplicates(int arr[], int n)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int test;
    cout<<"Enter number of Test Cases: "<<endl;
    cin>>test;
    for (int i = 0; i < test; i++)
    {
        int size;
        cout<<"Enter Size: "<<endl;
        cin>>size;
        int a[size];
        cout<<"Enter Elements: "<<endl;
        for(int j=0;j<size;j++){
            cin>>a[j];
        }


        if (has_duplicates(a, size))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
