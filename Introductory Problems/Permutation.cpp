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
ll t=1,n,k,a,b,q,x,y;

void solve() {
    cin>>n;
    if (n == 1) {
        cout << 1 << '\n';
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else {
        // print evens
        for (long long i = 2; i <= n; i += 2) {
            cout << i << (i + 2 <= n ? ' ' : ' ');
        }
        // print odds
        for (long long i = 1; i <= n; i += 2) {
            cout << i << (i + 2 <= n ? ' ' : '\n');
        }
    }

}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}