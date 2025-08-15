#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];

    vector<int> dp(m + 1, 1e7);
    dp[0] = 0;

    for(int i = 1; i <= m; i++) {
        for(int k : coin) {
            if(i - k >= 0)
                dp[i] = min(dp[i], dp[i - k] + 1);
        }
    }

    if(dp[m] >= 1e7)
        cout << -1 << endl;
    else
        cout << dp[m] << endl;

    return 0;
}

