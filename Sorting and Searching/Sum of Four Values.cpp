#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (auto &v : a) cin >> v;

    // sum -> pair of indices
    unordered_map<long long, pair<int, int>> mp;

    for (int j = 0; j < n; j++) {

        // Look for a pair (i, j2) whose sum complements a[j] + a[k]
        for (int k = j + 1; k < n; k++) {
            long long needed = x - a[j] - a[k];

            if (mp.count(needed)) {
                auto [i1, i2] = mp[needed];

                cout << i1 + 1 << " "
                     << i2 + 1 << " "
                     << j + 1 << " "
                     << k + 1 << '\n';

                return 0;
            }
        }

        // Add pairs ending at j only AFTER querying.
        // Therefore, when j is used above, every stored pair
        // has indices strictly smaller than j.
        for (int i = 0; i < j; i++) {
            long long sum = a[i] + a[j];

            // Any pair with this sum is sufficient.
            if (!mp.count(sum)) {
                mp[sum] = {i, j};
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}