#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;

inline ll fastpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
        ll A, B, C;
        cin >> A >> B >> C;
        cout << fastpow(A, fastpow(B, C, MOD - 1), MOD) << '\n';
    }

    return 0;
}
