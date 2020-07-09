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

const int N = 1e5 + 10;

int t;
char S[N];

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%s", &s);
        int ans = 0;
        int le = strlen (s);
        for (int i = le-1; i >= 0; i--) {
            s[i] -= '0';
            if (s[i]%2 == 0) break;
            ++ans;
            s[i] = '-';
        }
        if (ans == le) printf ("Cilada\n");
        else {
            
        }
    }

	return 0;
}
