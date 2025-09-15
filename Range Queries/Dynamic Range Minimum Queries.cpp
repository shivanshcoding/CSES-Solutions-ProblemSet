
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

struct SegTreeMin {
    int n;
    vector<ll> seg;

    SegTreeMin(int n) : n(n), seg(4*n, LLONG_MAX) {}

    void build(int idx, int l, int r, const vector<ll>& a) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*idx+1, l, mid, a);
        build(2*idx+2, mid+1, r, a);
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx+1, l, mid, pos, val);
        else update(2*idx+2, mid+1, r, pos, val);
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[idx];
        if (r < ql || l > qr) return LLONG_MAX;
        int mid = (l + r) / 2;
        return min(query(2*idx+1, l, mid, ql, qr),
                   query(2*idx+2, mid+1, r, ql, qr));
    }
};



void solve() {
    cin>>n>>q;
    vector<ll> a(n);
    read(a);
    SegTreeMin* sgt = new SegTreeMin(n);
    sgt->build(0,0,n-1,a);
    while(q--){
        cin>>x>>y>>z;
        y--;
        if(x==2){
            z--;
            cout<<sgt->query(0,0,n-1,y,z)<<endl;
        }else{
            sgt->update(0,0,n-1,y,z);
        }
    }
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}