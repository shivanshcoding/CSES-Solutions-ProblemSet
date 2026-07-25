#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define prDouble(x) cout << fixed << setprecision(10) << x
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using tll = tuple<ll,ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

vector<ll> dx = {1,-1,0,0}, dy = {0,0,1,-1};
vector<ll> ddx = {1,1,0,-1,-1,-1,0,1}, ddy = {0,1,1,1,0,-1,-1,-1};

template<typename T> void read(vector<T> &v){ for(auto &x:v) cin>>x; }
template<typename T> void printv(const vector<T>& v){ for(auto &x:v) cout<<x<<" "; }
template<typename T> void print2d(const vector<vector<T>>& v){ for(auto &r:v){ for(auto &x:r) cout<<x<<" "; cout<<"\n"; } }

ll t=1,n,m,p,q,r,k,a,b,c,x,y,z;
const ll INF=1e18, MOD=1e9+7;

bool ok(vector<int> &cnt, int last){
    int rem = 0;
    for(int x:cnt) rem += x;
    if(rem==0) return true;

    int mx = 0;
    for(int x:cnt) mx = max(mx, x);

    if(mx > (rem + 1) / 2) return false;
    if(last != -1 && cnt[last] > rem - cnt[last]) return false;

    return true;
}

void solve() {
    string s;
    cin >> s;

    vector<int> cnt(26,0);
    for(char ch:s) cnt[ch-'A']++;

    int N = s.size();
    int mx = *max_element(all(cnt));
    if(mx > (N + 1) / 2){
        cout << -1;
        return;
    }

    string ans = "";
    int last = -1;

    for(int pos=0; pos<N; pos++){
        bool found = false;

        for(int ch=0; ch<26; ch++){
            if(cnt[ch]==0) continue;
            if(ch==last) continue;

            cnt[ch]--;
            if(ok(cnt, ch)){
                ans.push_back(char('A'+ch));
                last = ch;
                found = true;
                break;
            }
            cnt[ch]++;
        }

        if(!found){
            cout << -1;
            return;
        }
    }

    cout << ans;
}

int main() {
    fastio();
    // cin >> t;
    while(t--) solve();
    return 0;
}