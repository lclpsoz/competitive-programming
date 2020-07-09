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
char str[5];
int v[10], d[10];

int main () {
    scanf ("%d %d", &n, &m);
    n*=m;
    while (n--) {
        scanf (" %s", str);
        if (str[1] == 'V') {
            v[str[0]-'0']++;
        } else {
            d[str[0]-'0']++;
        }
    }
    for (int i = 9; i >= 0; i--)
        while (v[i]--)
            printf ("%dV\n", i);
    for (int i = 9; i >= 0; i--)
        while (d[i]--)
            printf ("%dD\n", i);

	return 0;
}
