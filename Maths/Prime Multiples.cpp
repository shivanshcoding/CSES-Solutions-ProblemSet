#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;

    vector<long long> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    long long ans = 0;

    for (int mask = 1; mask < (1 << k); mask++) {
        __int128 prod = 1;
        int bits = 0;
        bool overflow = false;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                bits++;
                prod *= a[i];
                if (prod > n) {
                    overflow = true;
                    break;
                }
            }
        }

        if (overflow) continue;

        long long cnt = n / (long long)prod;

        if (bits % 2) ans += cnt;
        else ans -= cnt;
    }

    cout << ans << endl;
}