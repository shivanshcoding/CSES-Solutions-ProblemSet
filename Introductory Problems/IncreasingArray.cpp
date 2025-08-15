#include<bits/stdc++.h>
using namespace std;
vector<long long> arr;
int main(){
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long ch;
        cin>>ch;
        arr.push_back(ch);
    }
    long long ans = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            ans += arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout<<ans;
    return 0;
}
