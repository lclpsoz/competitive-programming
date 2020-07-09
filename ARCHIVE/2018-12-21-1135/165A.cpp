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

using pp = pair<pii, int>;

int n;
map<int, int> mp;
vector<pp> esq, dir;

void solve (vector<pp> &vec) {
	int bef = -(1e9);
	for (int i = 0; i < n-1; i++) {
		if (vec[i].x.x != bef)
			bef = vec[i].x.x;
		else if (vec[i+1].x.x == bef)
			mp[vec[i].y]++;
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		esq.push_back ({{x, y}, i});
		dir.push_back ({{y, x}, i});
	}
	sort (esq.begin(), esq.end());
	sort (dir.begin(), dir.end());
	solve (esq);
	solve (dir);
	
	int ans = 0;
	for (auto p : mp)
		if (p.y == 2)
			++ans;
	printf ("%d\n", ans);

	return 0;
}
