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

int n;
vector<int> vec;
vector<int> inc, de;

int main () {
    scanf ("%d", &n);
    while (n--) {
        int x;
        scanf ("%d", &x);
        vec.push_back (x);
    }
    sort (vec.begin(), vec.end());
    for (int v : vec) {
        if (inc.empty() or inc.back() != v) inc.push_back (v);
        else if (de.empty() or de.back() != v) de.push_back (v);
        else {
            printf ("NO\n");
            exit (0);
        }
    }
    sort (de.begin(), de.end(), greater<int>());
    printf ("YES\n");
    printf ("%d\n", len (inc));
    for (int i = 0; i < len (inc); i++) {
        printf ("%d", inc[i]);
        if (i < len (inc)-1) putchar (' ');
    }
    putchar ('\n');
    printf ("%d\n", len (de));
    for (int i = 0; i < len (de); i++) {
        printf ("%d", de[i]);
        if (i < len (de)-1) putchar (' ');
    }
    putchar ('\n');

	return 0;
}
