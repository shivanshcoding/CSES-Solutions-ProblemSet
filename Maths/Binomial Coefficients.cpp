#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXA = 1000000;

long long fact[MAXA+1], invfact[MAXA+1];

long long modpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1) res = res*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for(int i=1;i<=MAXA;i++)
        fact[i] = fact[i-1]*i % MOD;

    invfact[MAXA] = modpow(fact[MAXA], MOD-2);

    for(int i=MAXA-1;i>=0;i--)
        invfact[i] = invfact[i+1]*(i+1) % MOD;

    int n;
    cin >> n;

    while(n--){
        int a,b;
        cin >> a >> b;

        long long ans = fact[a];
        ans = ans * invfact[b] % MOD;
        ans = ans * invfact[a-b] % MOD;

        cout << ans << "\n";
    }
}