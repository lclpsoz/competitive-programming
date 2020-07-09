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

int n, m;
int mp[N];
vector<pii> vec;
vector<pii> ax;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
		mp[x]++, mp[y]++;
	}
	for (int i = 1; i <= n; i++)
		ax.push_back ({mp[i], i});
	sort (ax.begin(), ax.end(), greater<pii>());
	vector<pii> toTest;
	for (int i = 0; i < len (ax)-1; i++)
		for (int j = i+1; j < len (ax) and ax[i].x + ax[j].x >= m; j++)
			toTest.push_back ({ax[i].y, ax[j].y});

	for (auto pp : toTest) {
		if (pp.x > pp.y) swap (pp.x, pp.y);
		// printf ("|%d %d\n", pp.x, pp.y);
		bool ok = true;
		for (auto p : vec)
			if (p.x != pp.x and p.x != pp.y and p.y != pp.x and p.y != pp.y) {
				ok = false;
				break;
			}
		if (ok) {
			printf ("YES\n");
			exit (0);
		}
	}
	printf ("NO\n");

	return 0;
}
