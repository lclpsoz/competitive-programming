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

const int N = 2e5+100, V = 1e6+100;

int n;
int a[N];
ll pref[N], suf[N];
int qnt[V];
vector<int> ans;

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		pref[i] = pref[i-1] + a[i];
		qnt[a[i]]++;
	}
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i+1] + a[i];
	
	for (int i = 1; i <= n; i++) {
		qnt[a[i]]--;
		ll v = pref[i-1] + suf[i+1];
		if (v%2 == 0 and v/2 < V and qnt[v/2])
			ans.push_back (i);
		qnt[a[i]]++;
	}
	
	printf ("%d\n", len (ans));
	for (int i = 0; i < len (ans); i++) {
		if (i) putchar (' ');
		printf ("%d", ans[i]);
	}
	putchar ('\n');

	return 0;
}
