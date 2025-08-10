#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<ll> nodes;
vector<ll> subans;
vector<ll> ans;

void dfs(int u, int p){
    for(int k: adj[u]){
        if(k==p) continue;
        dfs(k,u);
        nodes[u] += nodes[k];
        subans[u] += (subans[k]+nodes[k]);
    }
}

void solve(int u, int p, ll p_ans, ll& n) {
    ans[u] = p_ans + (n-nodes[u]) + subans[u];
    for(int k: adj[u]){
        if(k==p) continue;
        solve(k,u,ans[u]-subans[k]-nodes[k],n);
    }
}


int main(){
    ll n;
    cin >> n;
    adj.resize(n);
    nodes.assign(n,1);
    subans.assign(n,0);
    ans.assign(n,0);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    solve(0,-1,0,n);
    for(ll i: ans){
        cout<<i<<" ";
    }
    return 0;
}