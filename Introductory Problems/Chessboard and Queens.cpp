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

vector<string> board(8);
bool col[8], diag1[15], diag2[15];
ll ans = 0;

void dfs(ll row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (ll c = 0; c < 8; c++) {
        if (board[row][c] == '*') continue;  // reserved square
        if (col[c] || diag1[row - c + 7] || diag2[row + c]) continue;
        col[c] = diag1[row - c + 7] = diag2[row + c] = true;
        dfs(row + 1);
        col[c] = diag1[row - c + 7] = diag2[row + c] = false;
    }
}

void solve() {
    for (ll i = 0; i < 8; i++) cin >> board[i];
    dfs(0);
    cout << ans << "\n";
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}