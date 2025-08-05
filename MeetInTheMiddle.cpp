#include<bits/stdc++.h>
using namespace std;
int n, t;
vector<int> arr;
vector<vector<int>> dp;

int Count(int sum, int i){
    if(i==n){
        if(sum==t) return 1;
        return 0;
    }
    if(dp[sum][i]!=-1) return dp[sum][i];
    int ans = 0;
    ans += Count(arr[i]+sum,i+1);
    ans += Count(sum,i+1);
    return dp[sum][i] = ans;
}

int main(){
    cin>>n>>t;
    long long sum = 0;
    for(int i=0;i<n;i++){
        int ch;
        cin>>ch;
        sum+= ch;
        arr.push_back(ch);
    } 
    dp.assign(sum+1, vector<int>(n,-1));
    cout<<Count(0,0);
    return 0;
}
