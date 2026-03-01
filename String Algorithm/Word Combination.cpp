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
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
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
vector<ll> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1}; // for grid
vector<ll> ddx = {1,1,0,-1,-1,-1,0,1}, ddy = {0,1,1,1,0,-1,-1,-1}; // 8 directions
template<typename T> void read(vector<T> &v) { for (auto &x : v) cin >> x; }
template<typename T> void printv(const vector<T>& v) { for (auto &x : v) cout << x << ' '; }
template<typename T> void print2d(const vector<vector<T>>& v) { for (auto &row : v) { for (auto &x : row) cout << x << ' '; cout << '\n'; } }
ll t=1,n,m,p,q,r,k,a,b,c,x,y,z;
const ll INF = 1e18;

static const int MOD = 1e9 + 7;

struct Node {
    int next[26];
    int link = 0;
    vector<int> out;

    Node() {
        memset(next, -1, sizeof(next));
    }
};

vector<Node> trie(1);

void insert_word(const string &s) {
    int cur = 0;
    for(char c : s) {
        int x = c - 'a';
        if(trie[cur].next[x] == -1) {
            trie[cur].next[x] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].next[x];
    }
    trie[cur].out.push_back(s.size());
}

void build_aho() {
    queue<int> q;

    // initialize root transitions
    for(int c = 0; c < 26; c++) {
        if(trie[0].next[c] == -1)
            trie[0].next[c] = 0;
        else {
            q.push(trie[0].next[c]);
        }
    }

    // BFS
    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(int c = 0; c < 26; c++) {
            int u = trie[v].next[c];

            if(u == -1) {
                trie[v].next[c] = trie[trie[v].link].next[c];
                continue;
            }

            trie[u].link = trie[trie[v].link].next[c];

            // merge outputs (IMPORTANT)
            for(int len : trie[trie[u].link].out)
                trie[u].out.push_back(len);

            q.push(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        string w;
        cin >> w;
        insert_word(w);
    }

    build_aho();

    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    int state = 0;

    for(int i = 0; i < n; i++) {
        state = trie[state].next[s[i]-'a'];

        // process all matches ending at i
        for(int len : trie[state].out) {
            dp[i+1] = (dp[i+1] + dp[i+1-len]) % MOD;
        }
    }

    cout << dp[n] << '\n';
}