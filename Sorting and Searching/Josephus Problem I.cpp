#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    vector<int> order;
    bool skip = false; // false = keep, true = remove
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (skip) {
            order.push_back(x); // remove this child
        } else {
            q.push(x); // keep this child, move to back
        }
        skip = !skip; // alternate between keep/remove
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
