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

const int N = 3e5 + 10;
int a[N];
ll suf[N];
vector<pair<ll, int>> vec;
int link[N], sz[N];
int seg[N];

int find (int x) {
	if (x == link[x]) return x;
	return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x), y = find (y);
	if (sz[x] > sz[y]) swap (x, y);
	sz[y] += sz[x];
	link[x] = y;
}

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) sz[i] = 1, link[i] = i;
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);

	for (int i = n-1; i >= 0; i--) {
		suf[i] = suf[i+1] + a[i];
		if (i > 0)
			vec.push_back ({suf[i], i});
	}
	// printf ("here!\n");
	sort (vec.begin(), vec.end());
	for (int i = 0; i < n-k; i++)
		unite (vec[i].y, vec[i].y-1);

	for (int i = 0; i < n; i++)
		seg[i] = find (i);
	ll ans = 0;
	ll q = 1;
	for (int i = 0; i < n; i++) {
		if (i and seg[i] != seg[i-1]) ++q;
		// printf ("%d: %lld\n", i, q);
		ans += a[i]*q;
	}
	printf ("%lld\n", ans);
		

	return 0;
}
