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

int n, m;
int ans;
stack<ll> a, b;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        a.push (x);
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf ("%d", &x);
        b.push (x);
    }
    bool test = true;
    while (test and a.size() and b.size()) {
        test = false;
        if (a.top() == b.top()) {
            ++ans;
            a.pop(); b.pop();
            test = true;
        } else {
            if (b.top() > a.top())
                swap (a, b);
            if (b.size() > 1) {
                ll ax = b.top();
                b.pop();
                ax += b.top();
                b.pop();
                b.push (ax);
                test = true;
            }
        }
    }
    if (len (a) || len (b))
        printf ("-1\n");
    else
        printf ("%d\n", ans);
    
    return 0;
}
