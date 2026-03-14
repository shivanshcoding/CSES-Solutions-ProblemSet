#include <bits/stdc++.h>
using namespace std;

class Fenwick {
public:
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    long long query(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    Fenwick ft(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            long long u;
            cin >> a >> b >> u;

            ft.update(a, u);
            if (b + 1 <= n) ft.update(b + 1, -u);
        }
        else {
            int k;
            cin >> k;
            cout << x[k] + ft.query(k) << "\n";
        }
    }
}