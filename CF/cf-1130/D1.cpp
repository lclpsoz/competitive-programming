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

const int N = 105;

int n, m;
vector<vector<pii>> verts;
multiset<int> train;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		verts.push_back ({});
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		int dist = b-a;
		if (dist < 0) dist += n;
		verts[a].push_back ({dist, b});
	}
	for (int i = 1; i <= n; i++)
		sort (verts[i].begin(), verts[i].end());

	for (int st = 1; st <= n; st++) {
		int pos = st-1;
		int qnt = m;
		int ans = 0;
		auto aux = verts;
		while (qnt) {
			++ans;
			++pos;
			// printf ("pos = %d, ans = %d, qnt = %d, len = %d\n", pos, ans, qnt, len (train));
			if (!train.empty()) {
				qnt -= train.count (pos);
				train.erase (pos);
			}

			if (!aux[pos].empty()) {
				train.insert (aux[pos].back().y);
				aux[pos].pop_back();
			}

			pos %= n;
		}
		printf ("%d ", ans - 1);
	}
	putchar ('\n');

	return 0;
}
