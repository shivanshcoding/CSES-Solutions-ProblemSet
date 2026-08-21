#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    multiset<long long> window;

    long long ans = LLONG_MIN;

    for (int r = a; r <= n; r++) {
        // Add prefix[r - a]
        window.insert(prefix[r - a]);

        // Remove prefix[r - b - 1] if it is outside the valid range
        if (r - b - 1 >= 0) {
            window.erase(window.find(prefix[r - b - 1]));
        }

        // Minimum prefix in [r-b, r-a]
        ans = max(ans, prefix[r] - *window.begin());
    }

    cout << ans << '\n';

    return 0;
}