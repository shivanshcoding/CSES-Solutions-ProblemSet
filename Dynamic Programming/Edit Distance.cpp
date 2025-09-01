#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    vector<int> prev(m+1), curr(m+1);

    // base case
    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        curr[0] = i; // base case
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1]; // no operation needed
            } else {
                curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
            }
        }
        swap(prev, curr);
    }

    cout << prev[m] << "\n";
    return 0;
}
