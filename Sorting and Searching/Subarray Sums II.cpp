#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    unordered_map<long long, long long> freq;

    // Empty prefix
    freq[0] = 1;

    long long sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        sum += a;

        // Number of previous prefix sums equal to sum - x
        ans += freq[sum - x];

        freq[sum]++;
    }

    cout << ans << '\n';

    return 0;
}