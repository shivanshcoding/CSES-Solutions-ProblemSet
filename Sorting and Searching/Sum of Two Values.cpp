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
    cin >> n >> x;

    vector<pair<long long,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // store original index (1-based)
    }

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    while (i < j) {
        long long sum = arr[i].first + arr[j].first;
        if (sum == x) {
            cout << arr[i].second << " " << arr[j].second << "\n";
            return;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}