#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int nxt : adj[node]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    if (order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int x : order)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}