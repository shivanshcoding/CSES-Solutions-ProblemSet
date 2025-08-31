#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> prev(m+2, 0), curr(m+2, 0);

    // base case
    if (a[0] == 0) {
        for (int val=1; val<=m; val++) prev[val] = 1;
    } else {
        prev[a[0]] = 1;
    }

    for (int i=1; i<n; i++) {
        fill(curr.begin(), curr.end(), 0);
        if (a[i] == 0) {
            for (int val=1; val<=m; val++) {
                long long ways = 0;
                ways += prev[val];
                ways += prev[val-1];
                ways += prev[val+1];
                curr[val] = ways % MOD;
            }
        } else {
            int val = a[i];
            long long ways = 0;
            ways += prev[val];
            ways += prev[val-1];
            ways += prev[val+1];
            curr[val] = ways % MOD;
        }
        prev.swap(curr);
    }

    long long ans = 0;
    for (int val=1; val<=m; val++) {
        ans = (ans + prev[val]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
