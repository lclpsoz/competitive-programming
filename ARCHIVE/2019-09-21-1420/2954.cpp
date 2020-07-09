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

const int N = 100100;

int n;
char str[N];
char jg[] = "jogo";

bool check (int pos) {
    for (int i = 0; i < 4; i++)
        if (jg[i] != str[i+pos-3]) return false;
    return true;
}

int main () {
    scanf ("%d", &n);
    while (n--) {
        scanf (" %[^\n] ", str);
        int mx = 0, acu = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = tolower (str[i]);
            if (str[i] >= 'a' and str[i] <= 'z') ++acu;
            mx = max (mx, acu);
            if (i >= 3 and check (i))
                acu = 0;
        }
        printf ("%d\n", mx);
    }

	return 0;
}
