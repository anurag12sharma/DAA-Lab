#include<iostream>
using namespace std;
void insertionsort(int arr[],int array_size)
{
    int i,j,t=0,comparison=0,shift=0;
    for(i=1;i<array_size;i++)
    {
        t=arr[i];
        j=i-1;
        shift++;
        while(j>=0&&t<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
            shift++;
            comparison++;
        }
        arr[j+1]=t;
    }
    for(i=0;i<array_size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Shifts = "<<shift<<endl<<"Comparisons = "<<comparison<<endl;
}
int main()
{
    int arr[10],array_size,testcase,i,j;
    cout<<"Input number of test cases"<<endl;
    cin>>testcase;
    while(testcase--){
    cout<<"Input array size"<<endl;
    cin>>array_size;
    cout<<"Input array elements"<<endl;
    for(i=0;i<array_size;i++)
    {
        cin>>arr[i];
    }
    insertionsort(arr,array_size);
    }
}

