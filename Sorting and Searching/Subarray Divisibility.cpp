#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> freq(n, 0);

    // Empty prefix sum has remainder 0
    freq[0] = 1;

    long long prefix = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        prefix += x;

        long long rem = ((prefix % n) + n) % n;

        // Every previous prefix with the same remainder
        // forms a valid subarray ending here.
        ans += freq[rem];

        freq[rem]++;
    }

    cout << ans << '\n';

    return 0;
}