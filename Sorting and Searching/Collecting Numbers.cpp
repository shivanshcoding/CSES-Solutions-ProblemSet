#include <bits/stdc++.h>
using namespace std;
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
template<typename T> void printv(const vector<T>& v) { for (auto &x : v) cout << x << ' '; }
template<typename T> void print2d(const vector<vector<T>>& v) { for (auto &row : v) { for (auto &x : row) cout << x << ' '; cout << '\n'; } }
ll t=1,n,k,a,b,q,x,y, MOD = 1e9+7;

void solve() {
    cin >> n;
    vector<ll> pos(n+1);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pos[x] = i;  // store position of each number
    }

    ll rounds = 1;
    for (ll i = 1; i < n; i++) {
        if (pos[i+1] < pos[i]) rounds++;
    }

    cout << rounds << "\n";
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}