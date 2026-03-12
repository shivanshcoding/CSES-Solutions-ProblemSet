#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    const int B = 31;
    vector<int> cnt(B, 0);

    long long ans = 0;
    long long cur_or = 0;

    queue<long long> q;

    long long cur = x;

    for (long long i = 1; i <= n; i++) {

        if (i > 1) cur = (a * cur + b) % c;

        q.push(cur);

        for (int bit = 0; bit < B; bit++) {
            if (cur & (1LL << bit)) cnt[bit]++;
        }

        if (q.size() > k) {
            long long rem = q.front();
            q.pop();

            for (int bit = 0; bit < B; bit++) {
                if (rem & (1LL << bit)) cnt[bit]--;
            }
        }

        if (q.size() == k) {
            cur_or = 0;
            for (int bit = 0; bit < B; bit++) {
                if (cnt[bit] > 0) cur_or |= (1LL << bit);
            }
            ans ^= cur_or;
        }
    }

    cout << ans << "\n";
}