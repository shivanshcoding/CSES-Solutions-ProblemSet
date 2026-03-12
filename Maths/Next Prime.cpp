#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using u128 = __uint128_t;

ull mod_mul(ull a, ull b, ull mod) {
    return (u128)a * b % mod;
}

ull mod_pow(ull a, ull d, ull mod) {
    ull res = 1;
    while (d) {
        if (d & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool miller_test(ull n, ull a, ull d, int s) {
    ull x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (int i = 1; i < s; i++) {
        x = mod_mul(x, x, n);
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(ull n) {
    if (n < 2) return false;

    for (ull p : {2,3,5,7,11,13,17,19,23,29,31,37})
        if (n % p == 0)
            return n == p;

    ull d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    // Deterministic bases for 64-bit integers
    for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        if (!miller_test(n, a, d, s)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        unsigned long long n;
        cin >> n;

        if (n < 2) {
            cout << 2 << "\n";
            continue;
        }

        ull candidate = n + 1;
        if (candidate % 2 == 0) candidate++;

        while (!isPrime(candidate))
            candidate += 2;

        cout << candidate << "\n";
    }
}