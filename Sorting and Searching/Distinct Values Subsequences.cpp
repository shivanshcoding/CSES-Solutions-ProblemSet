#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<long long, long long> freq;
    for (auto x : arr) freq[x]++;

    long long ans = 1;
    for (auto &p : freq) {
        ans = (ans * (p.second + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD;  // remove empty subsequence
    cout << ans << "\n";

    return 0;
}
