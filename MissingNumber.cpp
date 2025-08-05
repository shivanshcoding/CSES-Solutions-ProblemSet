#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long z = 0;
    for(int i=1;i<=n;i++){
        z = (z^i);
    }
    for(int i=1;i<n;i++){
        long long k;
        cin>>k;
        z = (z^k);
    }
    cout<<z;
    return 0;
}
