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


int n, v;
stack<int> base, now;

int main () {
    while (scanf ("%d", &n), n) {
        scanf ("%d", &v);
        while (v != 0) {
            
            now.push (v);
            base.push (n);
            for (int i = 1; i < n; i++) {
                while (!now.empty() && now.top() == base.top()) {
                    now.pop();
                    base.pop();
                }
                base.push (n-i);
                scanf ("%d", &v);
                now.push (v);
            }
            printf ("%d %d\n", now.top(), base.top());
            while (!now.empty() && now.top() == base.top()) {
                now.pop();
                base.pop();
            }
            
            if (now.empty())
                printf ("Yes\n");
            else
                printf ("No\n");
            printf ("%d %d\n", len (now), len (base));
            scanf ("%d", &v);
        }
        putchar ('\n');
    }
    
    return 0;
}
