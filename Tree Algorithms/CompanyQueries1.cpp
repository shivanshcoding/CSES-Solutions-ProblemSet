#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
vector<vector<ll>> adj;

void dfs(ll u, ll p){
    dp[u][0] = p;
    for (int x = 1; x < 20; x++){
        if(dp[u][x-1]!=-1) dp[u][x] = dp[dp[u][x - 1]][x - 1];
        else dp[u][x] = -1;
    }
    for(int k: adj[u]){
        if(k==p) continue;
        dfs(k,u);
    }
}

ll solve(ll u, ll k){
    if(u==-1 || k==0) return u;
    for(int i=19;i>=0;i--){
        if(k>= (1<<i)){
            return solve(dp[u][i],k-(1<<i));
        }
    }
    return -1;
}

int main(){
    ll n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    dp.assign(n + 1, vector<ll>(20, -1));
    for (ll i = 2; i <= n; i++){
        ll v;
        cin>>v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    dfs(1,-1);
    while (q--){
        ll u, k;
        cin >> u >> k;
        cout << solve(u, k) << endl;
    }
    return 0;
}