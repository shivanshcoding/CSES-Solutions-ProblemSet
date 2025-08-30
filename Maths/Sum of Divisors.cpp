#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const long long MOD = 1'000'000'007LL;
    const long long INV2 = (MOD + 1) / 2; // modular inverse of 2
    long long n;
    if (!(cin >> n)) return 0;

    auto sum_range = [&](long long L, long long R) -> long long {
        // returns (L + ... + R) % MOD
        long long a = L % MOD, b = R % MOD;
        long long cnt = (R - L + 1) % MOD;
        long long sum = (a + b) % MOD;
        sum = (sum * cnt) % MOD;
        sum = (sum * INV2) % MOD;
        return sum;
    };

    long long ans = 0;
    for (long long i = 1; i <= n; ) {
        long long v = n / i;
        long long last = n / v;              // maximum d with floor(n/d) = v
        long long blockSum = sum_range(i, last);
        ans = (ans + ( (__int128)v % MOD * blockSum ) % MOD) % MOD;
        i = last + 1;
    }

    cout << ans % MOD << "\n";
    return 0;
}
