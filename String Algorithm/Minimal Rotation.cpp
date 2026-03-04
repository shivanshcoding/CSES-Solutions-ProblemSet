#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    string ss = s + s;
    int i = 0, j = 1, k = 0;

    while (i < n && j < n && k < n) {
        if (ss[i + k] == ss[j + k]) {
            k++;
        } else if (ss[i + k] > ss[j + k]) {
            i = i + k + 1;
            if (i <= j) i = j + 1;
            k = 0;
        } else {
            j = j + k + 1;
            if (j <= i) j = i + 1;
            k = 0;
        }
    }

    int pos = min(i, j);
    cout << ss.substr(pos, n) << "\n";
}