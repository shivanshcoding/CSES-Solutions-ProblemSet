#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k) {
    while (true) {
        if (n == 1) return 1;
        if (k <= n / 2) {
            return 2 * k;   // k-th even eliminated
        }
        // else, shift to next round (odds survive)
        k -= n / 2;
        n = (n + 1) / 2;
        // map back to original odd: f(n,k) = 2*f((n+1)/2, k) - 1
        return 2 * solve(n, k) - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
