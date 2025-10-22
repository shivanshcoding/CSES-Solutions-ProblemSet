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
ll t=1,n,m,p,q,r,k,a,b,c,x,y,z;
const ll INF = 1e18, MOD = 1e9+7;

void solve() {
    cin>>n>>m;
    vector<vector<pll>> adj(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n, vector<ll> (2,INF));
    dist[0][0] = 0;
    dist[0][1] = 0;
    priority_queue<tll,vector<tll>,greater<tll>> pq;
    pq.push({0,0,0});
    while(!pq.empty()){
        auto [d,node,st] = pq.top();
        pq.pop();
        if(d > dist[node][st]) continue;
        for(pll& p: adj[node]){
            if(dist[p.f][st] > d+ p.s){
                dist[p.f][st] = d+p.s;
                pq.push({d+p.s,p.f,st});
            }
            if(st==0){
                if(dist[p.f][1] > d + (p.s)/2){
                    dist[p.f][1] = d + p.s/2;
                    pq.push({d+p.s/2,p.f,1});
                }
            }
        }
    }
    cout<<min(dist[n-1][0],dist[n-1][1]);
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}