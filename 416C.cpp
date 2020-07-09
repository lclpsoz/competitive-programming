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
vector<pii> arr[1010];
vector<pii> tables;
vector<pii> ans;

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int c, p;
		scanf ("%d %d", &c, &p);
		arr[c].push_back ({i, p});
	}

	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		tables.push_back ({x, i});
	}
	sort (tables.begin(), tables.end());
	int p = 0;
	multiset<pii> st;
	ll ansV = 0;
	for (auto now : tables) {
		int id = now.y, sz = now.x;
		while (p <= sz) {
			for (auto pp : arr[p])
				st.insert ({-pp.y, pp.x});
			++p;
		}
		if (!st.empty()) {
			ansV += -st.begin()->x;
			ans.push_back ({st.begin()->y, id});
			st.erase (st.begin());
		}
	}
	printf ("%d %d\n", len (ans), ansV);
	for (auto pp : ans)
		printf ("%d %lld\n", pp.x, pp.y);

	return 0;
}
