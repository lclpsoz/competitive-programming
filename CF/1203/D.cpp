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

const int N = 2e5 + 10;

string s, t;
int frst[N], lst[N];

bool check (int sz) {
	for (int st = 0; st < len (s)-sz+1; st++) {
		int pos = 0;
		int en = st+sz-1;
		for (int i = 0; i < len (s); i++) {
			if (i == st) i = en;
			else {
				pos += t[pos] == s[i];
				// printf ("sz = %d, st = %d, en = %d, i = %d, pos = %d\n", sz, st, en, i, pos);
				if (pos == len (t)) return true;
			}
		}
	}
	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie (0);
	cin >> s >> t;
	int pos = 0;
	for (int i = 0; i <  len (s); i++) {
		if (s[i] == t[pos]) {
			frst[pos] = i;
			++pos;
			if (pos == len (t)) break;
		}
	}
	pos = len (t)-1;
	for (int i = len(s)-1; i >= 0; --i) {
		if (s[i] == t[pos]) {
			lst[pos] = i;
			--pos;
			if (pos == -1) break;
		}
	}
	// for (int i = 0; i < len (t); i++)
	// 	printf ("%d: %d %d\n", i, frst[i], lst[i]);
	int ans = max (lst[0], len (s) - frst[len(t)-1] - 1);
	for (int i = 0; i < len (t)-1; i++)
		ans = max (ans, lst[i+1] - frst[i] - 1);
	printf ("%d\n", ans);



	return 0;
}
