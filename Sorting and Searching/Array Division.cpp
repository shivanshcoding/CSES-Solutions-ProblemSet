#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        low = max(low, a[i]);
        high += a[i];
    }

    auto can = [&](long long limit) {
        int parts = 1;
        long long currentSum = 0;

        for (long long x : a) {
            if (currentSum + x <= limit) {
                currentSum += x;
            } else {
                parts++;
                currentSum = x;

                if (parts > k)
                    return false;
            }
        }

        return true;
    };

    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (can(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';

    return 0;
}