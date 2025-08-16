#include <bits/stdc++.h>
using namespace std;
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
template<typename T> void printv(const vector<T>& v) { for (auto &x : v) cout << x << ' '; }
template<typename T> void print2d(const vector<vector<T>>& v) { for (auto &row : v) { for (auto &x : row) cout << x << ' '; cout << '\n'; } }
ll t=1,n,k,a,b,q,x,y, MOD = 1e9+7;

void solve() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int oddCount = 0, oddChar = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            oddCount++;
            oddChar = i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    string left = "", middle = "";
    if (oddChar != -1) {
        middle.push_back(char('A' + oddChar));  // only one odd char
        freq[oddChar]--;                        // use up one
    }

    for (int i = 0; i < 26; i++) {
        left.append(freq[i] / 2, char('A' + i));
    }
    string right = left;
    reverse(right.begin(), right.end());

    cout << left + middle + right << "\n";
}

int main() {
    fastio();
    // cin >> t;
    while (t--) solve();
    return 0;
}