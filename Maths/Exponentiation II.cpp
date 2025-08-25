#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1; // Since MOD is prime

// Fast modular exponentiation
ll modpow(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod; // safe multiply
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            if (b == 0 && c == 0) cout << 1 << "\n"; // 0^0 = 1
            else cout << 0 << "\n"; // 0^positive = 0
            continue;
        }

        // exponent = b^c mod (MOD-1)
        ll exp = modpow(b, c, PHI);
        ll ans = modpow(a, exp, MOD);
        cout << ans << "\n";
    }
    return 0;
}
