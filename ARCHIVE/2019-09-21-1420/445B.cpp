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

const int N = 60;

int n, m;
int link[N], size[N];

int find (int x) {
    if (x == link[x]) return x;
    return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
    x = find (x), y = find (y);
    if (size[x] > size[y]) swap (x, y);
    size[y] += size[x];
    link[x] = y;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        link[i] = i, size[i] = 1;
    while (m--) {
        int x, y;
        scanf ("%d %d", &x, &y);
        if (!same (x, y)) unite (x, y);
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
        if (link[i] == i) {
            ans *= 1LL<<(size[i]-1);
//              printf ("%d: %d\n", i, size[i]);
        }
    printf ("%lld\n", ans);

	return 0;
}
