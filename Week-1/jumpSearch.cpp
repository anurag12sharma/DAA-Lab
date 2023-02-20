#include<iostream>
#include<math.h>
using namespace std;
int jumpSearch(int array[],int size,int key){
    int start = 0;
    int end = sqrt(size); 

    while(array[end] <= key && end < size) {
        start = end; 
        end += sqrt(size);
        if(end > size - 1)
            end = size; 
    }

    for(int i = start; i<end; i++) {
        if(array[i] == key)
            return i;
    }
   return -1;

}


int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int ans =jumpSearch(arr,9,8);
    cout<<"Index: "<<ans<<endl;
    return 0;
}