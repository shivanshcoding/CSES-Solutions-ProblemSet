#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int mid = n / 2;
    vector<ll> left_sums, right_sums;

    // Generate sums for left half
    for (int mask = 0; mask < (1 << mid); mask++) {
        ll sum = 0;
        for (int i = 0; i < mid; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        left_sums.push_back(sum);
    }

    // Generate sums for right half
    for (int mask = 0; mask < (1 << (n - mid)); mask++) {
        ll sum = 0;
        for (int i = 0; i < (n - mid); i++) {
            if (mask & (1 << i)) sum += arr[mid + i];
        }
        right_sums.push_back(sum);
    }

    // Sort right sums for binary search
    sort(right_sums.begin(), right_sums.end());

    ll ways = 0;
    for (ll s : left_sums) {
        ll target = x - s;
        auto range = equal_range(right_sums.begin(), right_sums.end(), target);
        ways += range.second - range.first;
    }

    cout << ways << "\n";
    return 0;
}
