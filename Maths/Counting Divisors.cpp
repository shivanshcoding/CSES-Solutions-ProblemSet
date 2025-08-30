#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXX = 1e6;
    vector<int> div_count(MAXX + 1, 0);

    // Precompute number of divisors
    for (int i = 1; i <= MAXX; i++) {
        for (int j = i; j <= MAXX; j += i) {
            div_count[j]++;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << div_count[x] << "\n";
    }
    return 0;
}
