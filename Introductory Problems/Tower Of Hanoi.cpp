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

vector<pll> moves;

void hanoi(ll n, ll from, ll to, ll aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    moves.push_back({from, to});
    hanoi(n - 1, aux, to, from);
}

void solve() {
     cin >> n;

    hanoi(n, 1, 3, 2);

    cout << moves.size() << "\n";
    for (auto &p : moves) {
        cout << p.f << " " << p.s << "\n";
    }
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}