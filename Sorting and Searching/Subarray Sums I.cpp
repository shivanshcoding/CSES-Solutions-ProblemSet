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

    long long sum = 0;
    long long ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum > x) {
            sum -= a[left];
            left++;
        }

        if (sum == x) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}