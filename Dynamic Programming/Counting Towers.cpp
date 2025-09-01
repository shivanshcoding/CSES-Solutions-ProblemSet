#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

struct Mat {
    int64 a[2][2];
    Mat() { memset(a, 0, sizeof(a)); }
};

Mat mul(const Mat &A, const Mat &B) {
    Mat C;
    for (int i=0;i<2;++i)
      for (int j=0;j<2;++j) {
        __int128 sum = 0;
        for (int k=0;k<2;++k) sum += (__int128)A.a[i][k]*B.a[k][j];
        C.a[i][j] = (int64)(sum % MOD);
      }
    return C;
}

Mat mpow(Mat base, long long e) {
    Mat R; R.a[0][0]=R.a[1][1]=1; R.a[0][1]=R.a[1][0]=0;
    while (e>0) {
        if (e&1) R = mul(R, base);
        base = mul(base, base);
        e >>= 1;
    }
    return R;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        long long n; cin>>n;
        if (n==1) { cout << 2 << '\n'; continue; }
        if (n==2) { cout << 8 << '\n'; continue; }

        // Companion matrix A = [[6, MOD-7],[1,0]] because -7 mod MOD
        Mat A;
        A.a[0][0] = 6 % MOD;
        A.a[0][1] = (MOD - 7) % MOD; // -7 modulo MOD
        A.a[1][0] = 1;
        A.a[1][1] = 0;

        Mat P = mpow(A, n-2); // A^(n-2)
        // V2 = [f(2), f(1)]^T = [8, 2]^T
        int64 f2 = 8, f1 = 2;
        int64 fn = ( ( (__int128)P.a[0][0]*f2 + (__int128)P.a[0][1]*f1 ) % MOD );
        cout << fn << '\n';
    }
    return 0;
}
