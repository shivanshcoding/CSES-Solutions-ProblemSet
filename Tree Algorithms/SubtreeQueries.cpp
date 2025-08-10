#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& val, vector<ll>& sum, vector<int>& par) {
    sum[u] = val[u];
    par[u] = p;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, adj, val, sum,par);
            sum[u] += sum[v];
        }
    }
}

void solve(vector<ll>& sum, vector<int>& val, vector<int>& par, int s, int x) {
    int store = s;
    while(s!=-1){
        sum[s] = sum[s] - val[store] + x;
        s = par[s];
    }
    val[store] = x;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> val(n);
    vector<int> par(n,-1);
    vector<ll> sum(n,0);
    par[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1 ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, adj, val, sum, par);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int s, x;
            cin >> s >> x;
            s--;
            solve(sum,val,par,s,x);
        }else{
            int s;
            cin >> s;
            s--;
            cout << sum[s] << endl;
        }
    }
    return 0;
}