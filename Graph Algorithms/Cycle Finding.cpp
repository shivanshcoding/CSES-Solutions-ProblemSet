#include <bits/stdc++.h>
using namespace std;
// (Your template and defines)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
using pll = pair<ll,ll>;
using tll = tuple<ll,ll,ll>;
const ll INF = 1e18;

ll t=1,n,m,a,b,c;

// Store edges for Bellman-Ford
struct Edge {
    ll u, v, cost;
};

void solve() {
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        edges[i].u--; // Convert to 0-based
        edges[i].v--; // Convert to 0-based
    }

    vector<ll> dist(n, 0); // Init all dist to 0 works for finding any cycle
    vector<ll> par(n, -1);
    ll last_relaxed_node = -1;

    // Run N iterations
    for (int i = 0; i < n; ++i) {
        last_relaxed_node = -1;
        for (const auto& edge : edges) {
            ll u = edge.u;
            ll v = edge.v;
            ll cost = edge.cost;

            // Use INF check to avoid overflow with large positive/negative paths
            if (dist[u] == INF) continue; 

            if (dist[v] > dist[u] + cost) {
                // Using a large number < INF to prevent overflow
                // but still mark it as "worse" than a direct negative edge
                dist[v] = max(-INF, dist[u] + cost); 
                par[v] = u;
                last_relaxed_node = v;
            }
        }
    }

    // If no node was relaxed in the N-th iteration, no negative cycle
    if (last_relaxed_node == -1) {
        cout << "NO\n";
        return;
    }

    // A node was relaxed, so a negative cycle exists.
    // last_relaxed_node is in or reachable from a cycle.

    // To find a node *in* the cycle, go back N steps from the last relaxed node.
    // This guarantees you end up inside the cycle.
    ll node_in_cycle = last_relaxed_node;
    for (int i = 0; i < n; ++i) {
        node_in_cycle = par[node_in_cycle];
    }

    // Now, trace the cycle starting from node_in_cycle
    vector<ll> cycle;
    ll curr = node_in_cycle;
    while (true) {
        cycle.push_back(curr);
        curr = par[curr];
        if (curr == node_in_cycle) { // We've returned to the start
            cycle.push_back(curr);
            break;
        }
    }
    
    // The cycle is stored backward, so reverse it
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (ll node : cycle) {
        cout << node + 1 << " "; // Convert back to 1-based
    }
    cout << "\n";
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}