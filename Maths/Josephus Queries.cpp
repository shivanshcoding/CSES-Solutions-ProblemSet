#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (static_cast<size_t>(p.first) << 32) ^ static_cast<size_t>(p.second);
    }
};

unordered_map<pair<int,int>, int, PairHash> memo;

int solve(int N, int K) {
    if (auto it = memo.find({N, K}); it != memo.end()) 
        return it->second;

    if (N == 1) 
        return memo[{N, K}] = 1;

    if (2 * K <= N) 
        return memo[{N, K}] = 2 * K;

    int newN = N / 2 + (N & 1);
    int newK = K - N / 2;

    if (N & 1) {
        int ans = solve(newN, newK);
        return memo[{N, K}] = ((2 * ans - 3) + (N + 1)) % (N + 1);
    } 
    return memo[{N, K}] = 2 * solve(newN, newK) - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--) {
        int N, K;
        cin >> N >> K;
        cout << solve(N, K) << '\n';
    }

    return 0;
}
