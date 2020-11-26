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

int n, t;
vector<pp> vec;

bool eval (int k) {
	vector<int> now;
	for (auto p : vec)
		if (p.x.x >= k)
			now.push_back (p.x.y);
	sort (now.begin(), now.end());
	
	if (len (now) < k)
		return false;
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += now[i];
	return sum <= t;
}

void solve (int k) {
	vector<pii> now;
	for (auto p : vec)
		if (p.x.x >= k)
			now.push_back ({p.x.y, p.y});
	sort (now.begin(), now.end());
	for (int i = 0; i < k; i++) {
		if (i) putchar (' ');
		printf ("%d", now[i].y);
	}
	putchar ('\n');
}

int main () {
	scanf ("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		int a, ti;
		scanf ("%d %d", &a, &ti);
		vec.push_back ({{a, ti}, i});
	}
	
	int l = 0, r = n;
	while (l < r) {
		int md = (l+r+1)/2;
		if (eval (md))
			l = md;
		else
			r = md-1;
	}
	
	printf ("%d\n", l);
	printf ("%d\n", l);
	solve (l);

	return 0;
}
