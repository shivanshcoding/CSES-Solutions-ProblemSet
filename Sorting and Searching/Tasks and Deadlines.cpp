#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks; // {duration, deadline}

    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    int64 cur = 0;
    int64 reward = 0;

    for (auto [a, d] : tasks) {
        cur += a;
        reward += (int64)d - cur;
    }

    cout << reward << "\n";
    return 0;
}