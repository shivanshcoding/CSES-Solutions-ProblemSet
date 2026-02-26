#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const long long PHI = MOD-1;

long long modpow(long long a, long long b, long long mod=MOD){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin>>n;

    long long cnt=1;     // number of divisors
    long long sum=1;     // sum of divisors
    long long prod=1;    // product of divisors

    long long div_cnt=1; // divisor count modulo (MOD-1)

    while(n--){
        long long p,k;
        cin>>p>>k;

        // 1) number of divisors
        cnt = cnt*(k+1)%MOD;

        // 2) sum of divisors
        long long term=(modpow(p,k+1)-1+MOD)%MOD;
        term = term*modpow(p-1,MOD-2)%MOD;
        sum = sum*term%MOD;

        // 3) product of divisors
        long long exponent = (k*(k+1)/2)%PHI;
        exponent = exponent*div_cnt%PHI;

        prod = modpow(prod,k+1)%MOD;
        prod = prod*modpow(p,exponent)%MOD;

        // update divisor count for next iteration
        div_cnt = div_cnt*(k+1)%PHI;
    }

    cout<<cnt<<" "<<sum<<" "<<prod;
}