#include<iostream>
#include<algorithm>
using namespace std;

void findPair(int a[],int size,int key){
    sort(a,a+size); //10 15 20 24 32 35
    int max;
    for(int i=0;i<size;i++){
        if(a[i]>key){
            max =i-1;
        }
    }
    for(int j=0;j<max;j++){
        for(int k=j;k<max;k++){
            if(a[j]+a[k]==key){
                cout<<a[j]<<" "<<a[k]<<endl;
                return;
            }
        }
    }

    cout<<"No such pair exists";


}

int main(){
    int test,key;
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
        cout<<"Enter Key: "<<endl;
        cin>>key;
        findPair(a,size,key);
    }

    return 0;


    // int a[]={10,32,35,24,20,15};
    // findPair(a,6,30);
}