#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;

ll n, k, a, b, c, x;

void solve() {
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    vector<int> last(32, -1); // last index where each bit was seen
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        // update last positions of set bits in x
        for (int bit = 0; bit < 32; bit++) {
            if (x & (1 << bit)) {
                last[bit] = i;
            }
        }

        // once we have a full window
        if (i >= k - 1) {
            int l = i - k + 1;
            ll window_or = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (last[bit] >= l) {
                    window_or |= (1LL << bit);
                }
            }
            ans ^= window_or;
        }

        // generate next number
        if (i < n - 1) {
            x = (a * x + b) % c;
        }
    }

    cout << ans << "\n";
}

int main() {
    fastio();
    solve();
    return 0;
}
