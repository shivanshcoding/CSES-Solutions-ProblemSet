#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    const int INF = 1e9;
    vector<vector<int>> monsterDist(n, vector<int>(m, INF));
    vector<vector<int>> playerDist(n, vector<int>(m, INF));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    
    queue<Node> q;
    int startX, startY;

    // Multi-source BFS for monsters
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterDist[i][j] = 0;
                q.push({i,j});
            }
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    char moveChar[4] = {'D','U','R','L'};

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int k=0;k<4;k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#') {
                if (monsterDist[nx][ny] > monsterDist[x][y] + 1) {
                    monsterDist[nx][ny] = monsterDist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    // BFS for player
    queue<Node> pq;
    playerDist[startX][startY] = 0;
    pq.push({startX,startY});

    while (!pq.empty()) {
        auto [x,y] = pq.front(); pq.pop();
        // Check if boundary reached safely
        if (x==0 || y==0 || x==n-1 || y==m-1) {
            cout << "YES\n";
            cout << playerDist[x][y] << "\n";
            // reconstruct path
            string path;
            int cx=x, cy=y;
            while (!(cx==startX && cy==startY)) {
                auto [px,py] = parent[cx][cy];
                for (int k=0;k<4;k++) {
                    if (px+dx[k]==cx && py+dy[k]==cy) {
                        path.push_back(moveChar[k]);
                        break;
                    }
                }
                cx=px; cy=py;
            }
            reverse(path.begin(), path.end());
            cout << path << "\n";
            return 0;
        }

        for (int k=0;k<4;k++) {
            int nx=x+dx[k], ny=y+dy[k];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#') {
                if (playerDist[nx][ny] > playerDist[x][y] + 1 &&
                    playerDist[x][y] + 1 < monsterDist[nx][ny]) {
                    playerDist[nx][ny] = playerDist[x][y] + 1;
                    parent[nx][ny] = {x,y};
                    pq.push({nx,ny});
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
