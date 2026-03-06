#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N], inStack[N];
int parent[N];
int n, m;
int startNode = -1, endNode = -1;

bool dfs(int u) {
    vis[u] = true;
    inStack[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
        else if (inStack[v]) {
            startNode = v;
            endNode = u;
            return true;
        }
    }

    inStack[u] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) break;
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
    for (int x : cycle) cout << x << " ";
}