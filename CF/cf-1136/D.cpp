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
const int FLAG = 1e9 + 1e8;
int n, m;
int ans;
map<int, int> mp;
vector<int> fila;
int natSt[N];
vector<int> vec[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		fila.push_back (x);
	}
	int nat = fila.back();
	while (m--) {
		int u, v;
		scanf ("%d %d", &u, &v);
		if (v == nat)
			natSt[u]++;
		vec[v].push_back (u);
	}
	fila.pop_back ();
	while (!fila.empty() and natSt[fila.back()]) {
		++ans;
		fila.pop_back ();
	}

	int qMin = 1;
	reverse (fila.begin(), fila.end());
	for (int now : fila) {
		// printf ("now: %d, natSt[1] = %d\n", now, natSt[1]);
		if (natSt[now] == qMin)
			++ans;
		else {
			for (int v : vec[now])
				natSt[v]++;
			qMin++;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
