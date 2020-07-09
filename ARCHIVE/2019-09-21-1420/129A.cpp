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

int main () {
    int n, total = 0;
    scanf ("%d", &n);
    int a[110];
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        total += a[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if ((total-a[i])%2 == 0)
            ++ans;
        
    printf ("%d\n", ans);

	return 0;
}
