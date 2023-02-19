#include<iostream>
using namespace std;
void linearSearch(int a[],int size,int key){
    bool flag=0;
    for(int i=0;i<size;i++){
        if(a[i]==key){
            cout<<"Present at "<<i+1<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"Not Present";
}


int main(){
    int rep;
    cout<<"Total Arrays: ";
    cin>>rep;
    for(int j=0;j<rep;j++){
        int a[10],n,key;
        cout<<"Enter the size: "<<endl;
        cin>>n;
        cout<<"Enter the elements: "<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<"Enter the key"<<endl;
        cin>>key;
        linearSearch(a,n,key);
    }
    return 0;
}