#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    map<long long, long long> freq;

    long long prefix = 0;
    long long ans = 0;

    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        prefix += a;

        auto it = freq.find(prefix - x);
        if (it != freq.end()) {
            ans += it->second;
        }

        freq[prefix]++;
    }

    cout << ans << '\n';

    return 0;
}