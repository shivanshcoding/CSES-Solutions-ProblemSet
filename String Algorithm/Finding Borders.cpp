#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi(n, 0);

    // Build prefix function (KMP)
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        // fallback until match or j=0
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    // Collect borders
    vector<int> borders;
    int len = pi[n - 1];

    while (len > 0) {
        borders.push_back(len);
        len = pi[len - 1];
    }

    // increasing order
    reverse(borders.begin(), borders.end());

    // print
    for (int x : borders)
        cout << x << " ";

    return 0;
}