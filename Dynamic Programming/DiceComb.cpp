#include<bits/stdc++.h>
using namespace std;
long long n, MOD = 1e9+7;
vector<long long> dp;

long long Ans(long long sum){
    if(sum==0){
        return dp[sum] = 1;
    }
    if(dp[sum]!=-1) return dp[sum];
    long long ans = 0;
    for(long long i=1;i<=6;i++){
        if(sum-i>=0){
            ans = (ans+Ans(sum-i))%MOD;
        }
    }
    return dp[sum] = ans;

}

int main(){
    cin>>n;
    dp.assign(n+1,-1);
    cout<<Ans(n);
    return 0;
}

