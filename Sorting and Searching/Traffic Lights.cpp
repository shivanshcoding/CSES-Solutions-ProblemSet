#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> x >> n;

    set<int> lights;
    multiset<int> segments;

    lights.insert(0);
    lights.insert(x);
    segments.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto it = lights.lower_bound(p);
        int right = *it;
        int left = *prev(it);

        // remove old segment
        segments.erase(segments.find(right - left));

        // add new segments
        segments.insert(p - left);
        segments.insert(right - p);

        lights.insert(p);

        cout << *segments.rbegin() << " ";
    }

    return 0;
}
