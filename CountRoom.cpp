#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
};

int n, m;
vector<vector<char>> grid;
vector<vector<int>> dist;
vector<vector<char>> parent; // To reconstruct the path

// Directions for moving: Up, Down, Left, Right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'}; // Matching with dx, dy

string reconstruct_path(int x, int y) {
    string path;
    while (grid[x][y] != 'A') {
        char move = parent[x][y];
        path.push_back(move);
        if (move == 'U') x++;
        else if (move == 'D') x--;
        else if (move == 'L') y++;
        else if (move == 'R') y--;
    }
    reverse(path.begin(), path.end()); // Reverse to get correct order
    return path;
}

bool bfs(int sx, int sy, string &ans) {
    queue<Node> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        int x = current.x, y = current.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = dir[i]; // Store the direction of movement
                q.push({nx, ny});

                if (grid[nx][ny] == 'B') {
                    ans = reconstruct_path(nx, ny);
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    dist.assign(n, vector<int>(m, -1)); // -1 means unvisited
    parent.assign(n, vector<char>(m, 0));

    int sx = -1, sy = -1;

    // Read grid and find 'A'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }

    string ans;
    if (bfs(sx, sy, ans)) {
        cout << "YES\n" << ans.size() << endl << ans;
    } else {
        cout << "NO";
    }

    return 0;
}


