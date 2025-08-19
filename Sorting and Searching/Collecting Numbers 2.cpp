#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> x, pos;

// Function to update positions and count after swap
void update(int a, int b) {
    // Before swap: adjust cnt if relative order changes
    if (pos[x[a] - 1] <= pos[x[a]] && b < pos[x[a] - 1]) cnt++;
    if (pos[x[a] - 1] > pos[x[a]] && b >= pos[x[a] - 1]) cnt--;
    if (pos[x[a] + 1] >= pos[x[a]] && b > pos[x[a] + 1]) cnt++;
    if (pos[x[a] + 1] < pos[x[a]] && b <= pos[x[a] + 1]) cnt--;
    pos[x[a]] = b;

    if (pos[x[b] - 1] <= pos[x[b]] && a < pos[x[b] - 1]) cnt++;
    if (pos[x[b] - 1] > pos[x[b]] && a >= pos[x[b] - 1]) cnt--;
    if (pos[x[b] + 1] >= pos[x[b]] && a > pos[x[b] + 1]) cnt++;
    if (pos[x[b] + 1] < pos[x[b]] && a <= pos[x[b] + 1]) cnt--;
    pos[x[b]] = a;

    // Swap values in array
    swap(x[a], x[b]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    x.resize(N + 2);
    pos.resize(N + 2);

    for (int i = 1; i <= N; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }
    pos[N + 1] = N + 1;

    // Initial count of "rounds"
    cnt = 1;
    int prev = 0;
    for (int i = 1; i <= N; i++) {
        if (prev > pos[i]) cnt++;
        prev = pos[i];
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        update(a, b);
        cout << cnt << "\n";
    }
    return 0;
}
