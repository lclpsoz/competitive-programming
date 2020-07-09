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

int mp[1000];


int main () {
    mp['A'] = 1650 - 1700;
    mp['C'] = 2000 - 15500;
    mp['S'] = 2000 - 1800;
    mp['M'] = 1000 - 450;
    mp['P'] = 13000;
    mp['K'] = 80 - 100;
    mp['B'] = 40;
    int n;
    scanf ("%d", &n);
    ll mn = 1e18;
    ll mx = -mn;
    ll mxLocal = 0, mnLocal = 0;
    while (n--) {
        char c;
        scanf (" %c", &c);
        if (c == 'N') continue;
        if (mp[c] > mp[c]+mxLocal)
            mxLocal = mp[c];
        else
            mxLocal += mp[c];
        if (mp[c] < mp[c]+mnLocal)
            mnLocal = mp[c];
        else
            mnLocal += mp[c];
//         printf ("%d %lld %lld\n", mp[c], mnLocal, mxLocal);
        mx = max (mx, mxLocal);
        mn = min (mn, mnLocal);
    }
    if (mx == -mn)
        printf ("0 0\n");
    else
        printf ("%lld %lld\n", mx, mn);

	return 0;
}
