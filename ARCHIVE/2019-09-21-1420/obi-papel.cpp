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

const int N = 1e5 + 10;

int n;
vector<int> a;
map<int, vector<int>> mp;

int eval (int h) {
	int ret = 1;
	bool sq = false;
	for (int i = 0; i < n; i++) {
		if (a[i] > h) sq = true;
		else {
			ret += sq;
			sq = false;
		}
	}
	if (sq) ++ret;
	return ret;
}

int main () {
	scanf ("%d", &n);
	int mx = -1;
	set<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (a.empty() or a.back() != x) {
			a.push_back (x);
			st.insert (x);
		}
	}
	
	if (len (a) == 1)
		mx = 2;
	else {
		for (int i = 0; i < len (a); i++)
			if (i == 0)
				mp[a[i]].push_back (a[i] > a[i+1] ? -1 : 0);
			else if (i == len (a)-1)
				mp[a[i]].push_back (a[i-1] < a[i] ? -1 : 0);
			else if (a[i-1] < a[i] and a[i] > a[i+1])
				mp[a[i]].push_back (-1);
			else if (a[i-1] > a[i] and a[i] < a[i+1])
				mp[a[i]].push_back (1);

		int now = 2;
		for (int v : st) {
			for (int x : mp[v])
				now += x;
			// printf ("v(%d): now(%d)\n", v, now);
			mx = max (mx, now);
		}
	}

	printf ("%d\n", mx);

	return 0;
}
