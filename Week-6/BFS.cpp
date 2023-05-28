#include<iostream>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;

bool bipart;

void color(int u,int curr){
    if(col[u]!= -1 && col[u]!=curr){
        bipart = false;
        return;
    }
    col[u]=curr;
    if(vis[u])
        return;
    vis[u]=true;
    for(auto i:adj[u]){
        color(i,curr^1);
    }
}

int main(){
    bipart = true;
    int ver,edge;
    cin>>ver>>edge;
    adj = vector<vector<int>>(ver);
    vis = vector<bool>(ver,false);
    col = vector<int>(edge,-1);
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            color(i,0);
        }
    }

    if(bipart){
        cout<<"Yes Bipartite"<<endl;
    }

    else{
        cout<<"Not Bipartite"<<endl;
    }
}