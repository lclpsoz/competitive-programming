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

int k, n;
char wrong[110];
char s[110];
map<char, int> mp[110];
int ans = 0;

int main () {
    scanf ("%d", &k);
    scanf ("%s", wrong);
    scanf ("%d", &n);
    while (n--) {
        scanf ("%s", s);
        for (int i = 0; i < k; i++)
            mp[i][s[i]]++;
    }
    
    for (int i = 0; i < k; i++) {
        int mx = 0;
        for (auto p : mp[i])
            if (p.x != wrong[i])
                mx = max (p.y, mx);
        ans += mx;
    }
    printf ("%d\n", ans);

	return 0;
}
