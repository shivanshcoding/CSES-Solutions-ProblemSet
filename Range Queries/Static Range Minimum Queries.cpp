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
ll t=1,n,m,p,q,r,k,a,b,c,x,y,z,u,v;
const ll INF = 1e18, MOD = 1e9+7;

vector<ll> segT;

void build(ll ind, const vector<ll>& a, ll l, ll r ){
    if(l==r){
        segT[ind] = a[l];
        return;
    }
    ll mid = l+((r-l)/2);
    build(2*ind+1,a,l,mid);
    build(2*ind+2,a,mid+1,r);
    segT[ind] = min(segT[2*ind+1],segT[2*ind+2]);
}

ll query(ll ind, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) return segT[ind];   // total overlap
    if (r < ql || l > qr) return INF;           // no overlap
    ll mid = (l + r) / 2;
    return min(query(2*ind+1, l, mid, ql, qr),
               query(2*ind+2, mid+1, r, ql, qr));
}


void solve() {
    cin>>n>>q;
    segT.resize(4*n);
    vector<ll> a(n);
    read(a);
    build(0,a,0,n-1);
    while(q--){
        cin>>u>>v;
        u--;v--;
        cout<<query(0,0,n-1,u,v)<<endl;
    }

}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}