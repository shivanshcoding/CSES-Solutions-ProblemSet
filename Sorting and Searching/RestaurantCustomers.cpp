#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;



    vector<pair<int,int>> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, +1}); // arrival
        events.push_back({b, -1}); // leaving
    }

    sort(events.begin(), events.end());

    int current = 0, max_customers = 0;
    for (auto &e : events) {
        current += e.second;
        max_customers = max(max_customers, current);
    }

    cout << max_customers;
    return 0;
}
