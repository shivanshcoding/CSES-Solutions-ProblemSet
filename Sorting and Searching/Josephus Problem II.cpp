#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    ordered_set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    long long idx = 0; 
    vector<int> ans;
    for (int rem = n; rem > 0; rem--) {
        idx = (idx + k) % rem;  
        auto it = s.find_by_order(idx); // get element at idx
        ans.push_back(*it);
        s.erase(it);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i+1==n ? '\n' : ' ');
    }
}
