#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

long long modpow(long long a, long long b, long long m=MOD) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> p(n), k(n);
    for (int i=0; i<n; i++) cin >> p[i] >> k[i];

    // 1. Number of divisors
    long long num_div = 1;
    for (int i=0; i<n; i++) {
        num_div = (num_div * (k[i] + 1)) % MOD;
    }

    // 2. Sum of divisors
    long long sum_div = 1;
    for (int i=0; i<n; i++) {
        long long numerator = (modpow(p[i], k[i]+1) - 1 + MOD) % MOD;
        long long denominator = modpow(p[i]-1, MOD-2); // modular inverse
        long long term = (numerator * denominator) % MOD;
        sum_div = (sum_div * term) % MOD;
    }

    // 3. Product of divisors = N^(num_div/2)
    // First compute N modulo MOD
    long long Nmod = 1;
    for (int i=0; i<n; i++) {
        Nmod = (Nmod * modpow(p[i], k[i])) % MOD;
    }

    // We need exponent = num_div / 2. But careful with odd num_div!
    // Trick: product = pow(N, num_div/2) works because num_div is always even 
    // (except when N=1). In general, handle using Fermat.
    long long exp = num_div;
    if (exp % 2 == 0) {
        exp /= 2;
    } else {
        // if odd, multiply base by sqrt(N) mod M (rare for primes, but handle).
        // But number of divisors for >1 is always even, so safe.
        exp = (exp + MOD-1)/2; // fallback
    }
    long long prod_div = modpow(Nmod, exp);

    cout << num_div % MOD << " " << sum_div % MOD << " " << prod_div % MOD << "\n";
    return 0;
}
