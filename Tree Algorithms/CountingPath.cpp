#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }
size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM =
       chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using tll = tuple<ll,ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
vector<ll> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1}; // for grid
vector<ll> ddx = {1,1,0,-1,-1,-1,0,1}, ddy = {0,1,1,1,0,-1,-1,-1}; // 8 directions
template<typename T> void read(vector<T> &v) { for (auto &x : v) cin >> x; }
template<typename T> void printv(const vector<T>& v) { for (auto &x : v) cout << x << ' '; }
template<typename T> void print2d(const vector<vector<T>>& v) { for (auto &row : v) { for (auto &x : row) cout << x << ' '; cout << '\n'; } }
// ll t=1,n,m,p,q,r,k,a,b,c,x,y,z;
const ll INF = 1e18, MOD = 1e9+7;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
long long cnt[MAXN];
int parent[MAXN];
int n, m;

/* ---------- DFS to build LCA ---------- */
void dfs(int node, int par, int d){
    parent[node] = par;
    depth[node] = d;
    up[node][0] = par;

    for(int i = 1; i < LOG; i++){
        if(up[node][i-1] != 0)
            up[node][i] = up[ up[node][i-1] ][i-1];
    }

    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, d+1);
    }
}

/* ---------- LCA ---------- */
int lca(int a, int b){

    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];

    // lift a up
    for(int i = 0; i < LOG; i++)
        if(diff & (1<<i))
            a = up[a][i];

    if(a == b) return a;

    for(int i = LOG-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

/* ---------- Post-order accumulation ---------- */
void accumulate(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        accumulate(child, node);
        cnt[node] += cnt[child];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // root tree at 1
    dfs(1,0,0);

    /* ----- process queries ----- */
    while(m--){
        int a,b;
        cin>>a>>b;

        int L = lca(a,b);

        cnt[a]++;
        cnt[b]++;
        cnt[L]--;
        if(parent[L] != 0)
            cnt[parent[L]]--;
    }

    /* ----- propagate ----- */
    accumulate(1,0);

    /* ----- output ----- */
    for(int i=1;i<=n;i++)
        cout<<cnt[i]<<" ";
}