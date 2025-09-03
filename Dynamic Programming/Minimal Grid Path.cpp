#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // BFS-like sets of active positions
    vector<pair<int,int>> cur, next;
    cur.push_back({0,0});
    string ans;
    ans.push_back(grid[0][0]);

    int totalSteps = 2*n - 2;
    for (int step = 1; step <= totalSteps; step++) {
        char best = 'Z' + 1;
        next.clear();
        // explore neighbors
        for (auto [x,y] : cur) {
            if (x+1 < n) {
                char c = grid[x+1][y];
                if (c < best) {
                    best = c;
                    next.clear();
                    next.push_back({x+1,y});
                } else if (c == best) {
                    next.push_back({x+1,y});
                }
            }
            if (y+1 < n) {
                char c = grid[x][y+1];
                if (c < best) {
                    best = c;
                    next.clear();
                    next.push_back({x,y+1});
                } else if (c == best) {
                    next.push_back({x,y+1});
                }
            }
        }
        ans.push_back(best);
        // remove duplicates
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        cur.swap(next);
    }

    cout << ans << "\n";
    return 0;
}
