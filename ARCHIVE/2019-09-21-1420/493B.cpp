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
ll f, s;
vector<int> v1, v2;

void a1 () {
    printf ("first\n");
    exit (0);
}

void a2 () {
    printf ("second\n");
    exit (0);
}

int main () {
    scanf ("%d", &n);
    bool firstWin = false;
    while (n--) {
        int x;
        scanf ("%d", &x);
        if (n == 0 and x > 0) firstWin = true;
        if (x > 0)
            f += x, v1.push_back (x);
        else
            s += -x, v2.push_back (-x);
    }
    if (f > s) a1 ();
    else if (f < s) a2 ();
    else {
        int mn = min (len (v1), len (v2));
        for (int i = 0; i < mn; i++)
            if (v1[i] > v2[i])
                a1();
            else if (v1[i] < v2[i])
                a2();
        if (firstWin) a1();
        a2();
    }

	return 0;
}
