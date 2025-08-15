#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vis;

void dfs(int i,vector<vector<int>>& adj){
    vis[i]=1;
    for(int k: adj[i]){
        if(vis[k]==0){
            dfs(k,adj);
        }
    }
}

int main(){
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n+1,0);
    vector<int> ans;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,adj);
            count++;
            ans.push_back(i);
        }
    }
    cout<<count-1<<endl;
    for(int i=1;i<count;i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    return 0;
}
