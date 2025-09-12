#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u-1, v-1, -w}); // negate weights
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;

    // Bellman-Ford (n-1) times
    for (int i = 0; i < n-1; i++) {
        for (auto [u,v,w] : edges) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Mark nodes affected by negative cycle
    vector<int> affected(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto [u,v,w] : edges) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = -INF;
                affected[v] = 1;
            }
            if (affected[u]) affected[v] = 1;
        }
    }

    if (affected[n-1]) {
        cout << -1 << "\n"; // infinite score possible
    } else {
        cout << -dist[n-1] << "\n"; // negate back
    }

    return 0;
}
