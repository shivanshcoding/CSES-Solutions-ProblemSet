#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(customers.begin(), customers.end());

    // {departure_time, room_number}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<int> ans(n);
    int rooms = 0;

    for (auto [a, b, idx] : customers) {
        if (!pq.empty() && pq.top().first < a) {
            auto [dep, room] = pq.top();
            pq.pop();
            ans[idx] = room;
            pq.push({b, room});
        } else {
            ++rooms;
            ans[idx] = rooms;
            pq.push({b, rooms});
        }
    }

    cout << rooms << "\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}