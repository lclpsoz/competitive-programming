#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int q;
ll n, m, k;

int main () {
    cin >> q;
    while (q--) {
        cin >> n >> m >> k;
        ll diag = min (n, m);
        ll straight = max (n-diag, m-diag);
        //cout << diag << ' ' << straight << '\n';
        ll total = diag + straight;
        if (total > k)
            cout << "-1\n";
        else {
            diag += straight - straight%2;
            straight %= 2;
            total = k-total;
            
            if (straight == 0) {
                if (total%2 == 0)
                    cout << diag + total << '\n';
                else
                    cout << diag + total - 2 << '\n';
            } else
                cout << diag + total << '\n';
        }
    }

    return 0;
}
