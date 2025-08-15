#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, parent;
int startNode = -1, endNode = -1;

bool dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue; // don't go back to parent
        if (!vis[v]) {
            parent[v] = u;
            if (dfs(v, u)) return true;
        } else {
            // found a back edge -> cycle
            startNode = v;
            endNode = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (startNode == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(startNode);
    for (int v = endNode; v != startNode; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(startNode);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";
}
