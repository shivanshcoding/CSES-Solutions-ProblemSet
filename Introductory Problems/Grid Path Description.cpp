#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[9][9];
int ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dc[4] = {'D', 'U', 'L', 'R'};

void dfs(int x, int y, int idx) {
    // Reached destination
    if (x == 7 && y == 1) {
        if (idx == 48) ans++;
        return;
    }

    // Used all moves but not at destination
    if (idx == 48) return;

    // Pruning: path gets split horizontally
    if (vis[x - 1][y] && vis[x + 1][y] &&
        !vis[x][y - 1] && !vis[x][y + 1])
        return;

    // Pruning: path gets split vertically
    if (vis[x][y - 1] && vis[x][y + 1] &&
        !vis[x - 1][y] && !vis[x + 1][y])
        return;

    vis[x][y] = true;

    if (s[idx] == '?') {
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!vis[nx][ny])
                dfs(nx, ny, idx + 1);
        }
    } else {
        int k;
        if (s[idx] == 'D') k = 0;
        else if (s[idx] == 'U') k = 1;
        else if (s[idx] == 'L') k = 2;
        else k = 3;

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (!vis[nx][ny])
            dfs(nx, ny, idx + 1);
    }

    vis[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    // Mark border as visited
    for (int i = 0; i < 9; i++) {
        vis[0][i] = vis[8][i] = true;
        vis[i][0] = vis[i][8] = true;
    }

    dfs(1, 1, 0);

    cout << ans << '\n';
    return 0;
}