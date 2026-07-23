#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        unsigned long long k;
        cin >> k;

        unsigned long long len = 1;
        unsigned long long cnt = 9;
        unsigned long long start = 1;

        while (true) {
            i128 digits = (i128)cnt * len;
            if ((i128)k > digits) {
                k -= (unsigned long long)digits;
                len++;
                cnt *= 10;
                start *= 10;
            } else {
                break;
            }
        }

        // Number containing the k-th digit
        unsigned long long num = start + (k - 1) / len;

        // Index of digit inside the number
        int idx = (k - 1) % len;

        string s = to_string(num);
        cout << s[idx] << '\n';
    }

    return 0;
}