#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const long long INV2 = 500000004; // modular inverse of 2

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    long long S = 1LL*n*(n+1)/2;

    if(S%2){
        cout<<0;
        return 0;
    }

    int target = S/2;

    vector<int> dp(target+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=target;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }

    long long ans = 1LL*dp[target]*INV2%MOD;
    cout<<ans;
}