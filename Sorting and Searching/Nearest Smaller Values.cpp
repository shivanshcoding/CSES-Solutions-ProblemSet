#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    vector<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {

        // Remove elements that are not smaller than a[i]
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }

        // Nearest smaller element to the left
        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.back() + 1;  // positions are 1-indexed

        st.push_back(i);
    }

    for (int x : ans)
        cout << x << ' ';

    cout << '\n';

    return 0;
}