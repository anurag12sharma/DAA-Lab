#include<iostream>
#include<algorithm>
using namespace std;

void intersection(int a[],int sizea,int b[],int sizeb){
    int ans[sizea+sizeb],ele=0;
    sort(a,a+sizea); 
    sort(b,b+sizeb);
    int i=0; 
    int j=0;
    while(i<sizea && j<sizeb){
        if(a[i]<b[j]) 
            i++;
        if(a[i]>b[j])
            j++;
        if(a[i]==b[j]){
            ans[ele]=a[i];
            ele++;
            i++;
            j++;
        }
        
        
    }
    cout<<endl;
    cout<<"Intersection: "<<endl;
    for(int k=0;k<ele;k++){
        cout<<ans[k]<<" ";
    }
    cout<<endl;
    


}


int main(){

    int sizea,sizeb;   
    cout<<"Enter size of first array:  "<<endl;
    cin>>sizea;
    int a[sizea];
    cout<<"Enter Elements: "<<endl;
    for(int j=0;j<sizea;j++){
        cin>>a[j];
    }

    cout<<"Enter size of second array:  "<<endl;
    cin>>sizeb;
    int b[sizeb];
    cout<<"Enter Elements: "<<endl;
    for(int j=0;j<sizeb;j++){
        cin>>b[j];
    }

    intersection(a,sizea,b,sizeb);

    return 0;
}