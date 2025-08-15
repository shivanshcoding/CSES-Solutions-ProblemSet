#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vis;

void bfs(vector<vector<int>>& adj, int i, bool& gadbad){
    queue<int> q;
    q.push(i);
    vis[i] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int k: adj[curr]){
            if(vis[k]==-1){
                vis[k] = !vis[curr]; 
                q.push(k);
            }else{
                if(vis[k]==vis[curr]){
                    gadbad = true;
                    return;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool gadbad = false;
    vis.assign(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            bfs(adj,i,gadbad);
            if(gadbad){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]+1<<" ";
    }
    return 0;
}
