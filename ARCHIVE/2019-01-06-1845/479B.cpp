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

const int N = 1e4+10;

int n, k, l, r;
stack<int> st[N];
vector<pii> ans;

int main () {
	scanf ("%d %d", &n, &k);
	if (n == 1)
		printf ("0 0\n");
	else {
		l = N;
		r = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf ("%d", &x);
			l = min (l, x);
			r = max (r, x);
			st[x].push (i);
		}
		
		for (int i = 0; l < r and i < k; i++) {
			int nowL = st[l].top(); st[l].pop();
			int nowR = st[r].top(); st[r].pop();
			ans.push_back ({nowR, nowL});
			st[l+1].push (nowL);
			st[r-1].push (nowR);
			
			while (st[r].empty()) --r;
			while (st[l].empty()) ++l;
		}
		printf ("%d %d\n", abs (r-l), len (ans));
		for (pii p : ans)
			printf ("%d %d\n", p.x, p.y);
	}

	return 0;
}
