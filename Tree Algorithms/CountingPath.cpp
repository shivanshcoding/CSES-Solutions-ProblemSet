#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[LOG][MAXN];
int depth[MAXN];
long long cnt[MAXN];
int parent[MAXN];
int n, m;

void dfs(int v, int p) {
    parent[v] = p;
    up[0][v] = p;

    for (int i = 1; i < LOG; i++) {
        up[i][v] = up[i-1][ up[i-1][v] ];
    }

    for (int to : adj[v]) {
        if (to == p) continue;
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i))
            a = up[i][a];
    }

    if (a == b) return a;

    for (int i = LOG-1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }

    return up[0][a];
}

void dfs2(int v, int p) {
    for (int to : adj[v]) {
        if (to == p) continue;
        dfs2(to, v);
        cnt[v] += cnt[to];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    while (m--) {
        int a,b;
        cin >> a >> b;

        int l = lca(a,b);

        cnt[a]++;
        cnt[b]++;
        cnt[l]--;

        if (parent[l])
            cnt[parent[l]]--;
    }

    dfs2(1,0);

    for (int i = 1; i <= n; i++)
        cout << cnt[i] << " ";

    cout << "\n";
}