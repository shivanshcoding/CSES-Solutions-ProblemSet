#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXX = 1e6;
    int n;
    cin >> n;

    vector<int> freq(MAXX + 1, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    // Check possible GCDs from largest to smallest
    for (int g = MAXX; g >= 1; g--) {
        int multiples = 0;
        for (int j = g; j <= MAXX; j += g) {
            multiples += freq[j];
            if (multiples >= 2) {
                cout << g << "\n";
                return 0;
            }
        }
    }

    return 0;
}
