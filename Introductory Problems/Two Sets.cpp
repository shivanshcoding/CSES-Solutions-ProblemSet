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
    cin >> n;

    long long sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<long long> set1, set2;
    long long target = sum / 2;

    for (long long i = n; i >= 1; i--) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (auto x : set1) cout << x << " ";
    cout << "\n";
    cout << set2.size() << "\n";
    for (auto x : set2) cout << x << " ";
    cout << "\n";
}
int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}