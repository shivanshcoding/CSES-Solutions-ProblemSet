#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1'000'000'007;

    int n, x;
    if (!(cin >> n >> x)) return 0;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int s = 1; s <= x; ++s) {
        long long ways = 0;
        for (int coin : c) {
            if (coin <= s) {
                ways += dp[s - coin];
                if (ways >= (long long)MOD * 4) ways %= MOD; // occasional reduce
            }
        }
        dp[s] = (int)(ways % MOD);
    }

    cout << dp[x] << '\n';
    return 0;
}
