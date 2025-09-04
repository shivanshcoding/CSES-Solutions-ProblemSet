#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll MOD = 1e9+7;

// Fast exponentiation
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// Modular inverse (Fermat’s Little Theorem)
ll modinv(ll k){
    return power(k, MOD-2);
}

void solve() {
    int n;
    cin >> n;
    vector<pll> pf(n);
    for(int i=0; i<n; i++){
        cin >> pf[i].first >> pf[i].second;
    }

    __int128 realCount = 1;   // actual divisor count (big integer)
    ll countMod = 1;          // divisor count modulo (MOD-1)
    ll sum = 1;               // sum of divisors
    ll prod = 1;              // product of divisors

    // Count & Sum
    for(auto& p: pf){
        ll fac = p.first, pw = p.second;

        realCount *= (pw + 1);   // exact count (can be very big!)
        countMod = (countMod * (pw + 1)) % (MOD-1);

        ll numerator = (power(fac, pw+1) - 1 + MOD) % MOD;
        ll denominator = modinv(fac - 1);
        sum = (sum * ((numerator * denominator) % MOD)) % MOD;
    }

    // Halfcount for product
    ll halfCount;
    if (realCount % 2 == 0) {
        halfCount = (countMod * modinv(2)) % (MOD-1);
    } else {
        halfCount = countMod; // odd divisor count (perfect square case)
    }

    // Product
    for(auto& p: pf){
        ll fac = p.first, pw = p.second;
        ll exponent = ((pw % (MOD-1)) * (halfCount % (MOD-1))) % (MOD-1);
        prod = (prod * power(fac, exponent)) % MOD;
    }

    // Print result (realCount fits in 64-bit since n ≤ 1e5, pw ≤ 1e9, but careful!)
    unsigned long long divisorCount = (unsigned long long)realCount;
    cout << divisorCount << " " << sum << " " << prod << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
