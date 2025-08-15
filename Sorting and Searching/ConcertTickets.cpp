#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        // find the first element greater than t
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
    return 0;
}
