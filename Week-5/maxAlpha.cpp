#include<iostream>
#include<algorithm>
using namespace std;
void maxAlpha(char a[],int size){
    int ans[26]={0};
    char check = 'a';
    for(int i=0;i<26;i++){
        for(int j=0;j<size;j++){
            if(a[j]==check){
                ans[i]++;
            }
        }
        check++;
    }

    int max=ans[0],ind;
    for(int k=1;k<26;k++){
        if(max<ans[k]){
           max=ans[k];
           ind = k;
        }
    }
    char var = 'a'+ind;
    cout<<"Maximum Occuring Character:"<<" "<<var;
    // for(int k=0;k<26;k++){
    //     cout<<ans[k]<<" ";
    // }
}
int main(){
    char a[]={'a','e','d','w','a','d','q','a','f','p'};
    maxAlpha(a,10);
}