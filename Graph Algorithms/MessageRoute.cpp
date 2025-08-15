#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{1,-1}});
    vector<int> dist(n+1,INT_MAX);
    vector<int> par(n+1,-1);
    while(!pq.empty()){
        auto curr = pq.top();
        int d =  curr.first;
        int node = curr.second.first;
        int p = curr.second.second;
        pq.pop();
        dist[node] = d;
        par[node] = p;
        for(int k: adj[node]){
            if(d+1 < dist[k]){
                dist[k] = d+1;
                par[k] = node;
                pq.push({d+1,{k,node}});
            }
        }
    }
    if(dist[n]==INT_MAX) cout<<"IMPOSSIBLE";
    else{
        cout<<dist[n]+1<<endl;
        vector<int> ans;
        int i = n;
        while(i!=-1){
            ans.push_back(i);
            i = par[i];
        }
        reverse(ans.begin(),ans.end());
        for(int i : ans){
            cout<<i<<" ";
        }
    }
    return 0;
}