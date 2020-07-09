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
int p[11110], ans[11110];
set<pair<pii, int>> st;

int main () {
	while (scanf ("%d", &n), n) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &p[i]);
			sum += p[i];
		}
		int a;
		scanf ("%d", &a);
		if (sum < a) {
			printf ("Impossible\n");
		} else {
			for (int i = 0; i < n; i++)
				if (p[i])
				st.insert ({{0, -p[i]}, i});
			sum = 0;
			int aa = a;
			while (a--) {
				auto now = *st.begin();
				st.erase (st.begin());
				ans[now.y]++;
				now.x.y++;
				now.x.x++;
				if (now.x.y)
					st.insert (now);
			}
			vector<int> vv;
			for (int i = 0; i < n; i++) vv.push_back (ans[i]), sum += ans[i];
			assert (sum == aa);
			sort (vv.begin(), vv.end(), greater<int>());
			for (int x : vv)
				printf ("%d\n", x);
		}
		memset (ans, 0, sizeof ans);
		st.clear();
	}

	return 0;
}
