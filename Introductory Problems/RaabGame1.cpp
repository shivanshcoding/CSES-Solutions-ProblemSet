#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> A, B;

        // Step 1: give A 'a' wins
        for (int i = 0; i < a; i++) {
            A.push_back(n - i);      // A gets large numbers
            B.push_back(i + 1);      // B gets small numbers
        }

        // Step 2: give B 'b' wins
        for (int i = 0; i < b; i++) {
            A.push_back(a + i + 1);  // A gets next available small
            B.push_back(n - i);      // B gets large numbers
        }

        // Step 3: remaining rounds are ties
        int used = a + b;
        for (int i = used + 1; i <= n; i++) {
            A.push_back(i);
            B.push_back(i);
        }

        // print result
        for (int x : A) cout << x << " ";
        cout << "\n";
        for (int x : B) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
