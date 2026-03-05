#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<long long,3>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        if (x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    });

    vector<int> contains(n), contained(n);

    long long max_r = 0;

    for (auto &x : a) {
        if (x[1] <= max_r) contained[x[2]] = 1;
        max_r = max(max_r, x[1]);
    }

    long long min_r = LLONG_MAX;

    for (int i = n - 1; i >= 0; i--) {
        auto &x = a[i];
        if (x[1] >= min_r) contains[x[2]] = 1;
        min_r = min(min_r, x[1]);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) cout << contained[i] << " ";
}