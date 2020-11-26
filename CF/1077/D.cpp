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

const int N = 2e5+10;

int n, k;
int qnt[N];
vector<pii> vec;

bool eval (int q) {
	int ax = k;
	for (int i = 0; ax > 0 and i < len (vec); i++)
		ax -= vec[i].x/q;
	
	return ax <= 0;
}

int bs (int l, int r) {
	while (l < r) {
		int md = (l+r+1)/2;
		if (eval (md))
			l = md;
		else
			r = md-1;
	}
	
	return l;
}

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		qnt[x]++;
	}
	for (int i = 1; i < N; i++)
		if (qnt[i])
			vec.push_back ({qnt[i], i});
		
	int q = bs (1, n);
	vector<int> ans;
	for (int i = 0; i < len (vec); i++)
		while (vec[i].x >= q) {
			vec[i].x -= q;
			ans.push_back (vec[i].y);
		}
		
	for (int i = 0; i < k; i++) {
		if (i) putchar (' ');
		printf ("%d", ans[i]);
	}
	putchar ('\n');

	return 0;
}
