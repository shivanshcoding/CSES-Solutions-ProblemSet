#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1000000;

long long C2(long long x){
    return x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> freq(MAXX + 1, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<long long> cnt(MAXX + 1, 0);

    for(int d = 1; d <= MAXX; d++){
        for(int multiple = d; multiple <= MAXX; multiple += d){
            cnt[d] += freq[multiple];
        }
    }

    vector<long long> f(MAXX + 1, 0);

    for(int d = MAXX; d >= 1; d--){
        f[d] = C2(cnt[d]);

        for(int multiple = 2*d; multiple <= MAXX; multiple += d){
            f[d] -= f[multiple];
        }
    }

    cout << f[1] << "\n";
}