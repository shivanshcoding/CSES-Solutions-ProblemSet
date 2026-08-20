#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> movies(n);

    for (auto &[start, end] : movies) {
        cin >> start >> end;
    }

    // Sort by ending time.
    sort(movies.begin(), movies.end(),
         [](const auto &x, const auto &y) {
             return x.second < y.second;
         });

    // Last ending time of each member.
    // Initially, everyone is available from time 0.
    multiset<long long> available;

    for (int i = 0; i < k; ++i) {
        available.insert(0);
    }

    int ans = 0;

    for (auto &[start, end] : movies) {

        // Find the first ending time > start.
        auto it = available.upper_bound(start);

        // No member is free before this movie starts.
        if (it == available.begin()) {
            continue;
        }

        // Use the member with the latest ending time <= start.
        --it;

        available.erase(it);
        available.insert(end);

        ++ans;
    }

    cout << ans << '\n';

    return 0;
}