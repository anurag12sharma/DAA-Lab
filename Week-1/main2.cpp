#include<iostream>
using namespace std;
int binarySearch(int a[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while (start <= end){
        if(a[mid]==key){
            return mid+1;
            break;
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else if(a[mid]<key)
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return -1;
}


int main(){
    int rep;
    cout<<"Total Arrays: ";
    cin>>rep;
    for(int j=0;j<rep;j++){
        int a[10],n,key,ans;
        cout<<"Enter the size: "<<endl;
        cin>>n;
        cout<<"Enter the elements: "<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<"Enter the key"<<endl;
        cin>>key;
        ans=binarySearch(a,n,key);
        cout<<"Present at "<<ans<<endl;
    }
    return 0;
}