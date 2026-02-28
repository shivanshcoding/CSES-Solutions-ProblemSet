#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL);

vector<int> build_lps(const string &pat) {
    int m = pat.size();
    vector<int> lps(m);

    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1]; // jump using lps
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    fastio();

    string text, pat;
    cin >> text >> pat;

    int n = text.size(), m = pat.size();
    vector<int> lps = build_lps(pat);

    int i = 0, j = 0;
    int ans = 0;

    while(i < n) {
        if(text[i] == pat[j]) {
            i++;
            j++;
        }

        if(j == m) {           // pattern found
            ans++;
            j = lps[j - 1];    // continue searching (handles overlaps)
        }
        else if(i < n && text[i] != pat[j]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << ans;
}