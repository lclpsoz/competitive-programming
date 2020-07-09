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

const int N = 1e3 + 10;

int n;
int a[N], asc[N], desc[N];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    
    for (int i = 0; i < n; i++)
        asc[i] = desc[i] = 1;
    
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                asc[i] = max (asc[i], asc[j] + 1);
    for (int i = n-2; i >= 0; i--)
        for (int j = n-1; j > i; j--)
            if (a[i] > a[j])
                desc[i] = max (desc[i], desc[j] + 1);
            
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans = max (ans, asc[i] + desc[i]);
    printf ("%d\n", ans);

	return 0;
}
