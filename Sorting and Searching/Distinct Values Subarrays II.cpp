#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    // Coordinate compression
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // Convert values to [0 ... distinct_values-1]
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }

    vector<int> freq(vals.size(), 0);

    int left = 0;
    int distinct = 0;
    long long ans = 0;

    for (int right = 0; right < n; right++) {

        if (freq[a[right]] == 0)
            distinct++;

        freq[a[right]]++;

        // Shrink window until it has <= k distinct values
        while (distinct > k) {
            freq[a[left]]--;

            if (freq[a[left]] == 0)
                distinct--;

            left++;
        }

        // Number of valid subarrays ending at right
        ans += right - left + 1;
    }

    cout << ans << '\n';

    return 0;
}