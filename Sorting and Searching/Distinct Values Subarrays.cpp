#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long ans = 0;
    unordered_map<long long, int> freq;
    int l = 0;

    for (int r = 0; r < n; r++) {
        freq[arr[r]]++;
        while (freq[arr[r]] > 1) {  // duplicate found
            freq[arr[l]]--;
            l++;
        }
        ans += (r - l + 1);  // number of subarrays ending at r
    }

    cout << ans << "\n";
    return 0;
}
