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

const int N = 1010;

int n;
int dep[N];
vector<int> adj[N];
vector<int> now;

int main () {
	while (scanf ("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			dep[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int m;
			scanf ("%d", &m);
			dep[i] = m;
// 			printf ("m: %d\n", m);
			while (m--) {
				int x; scanf ("%d", &x);
				adj[x].push_back (i);
			}
		}
// 		for (int i = 1; i <= n; i++)
// 			printf ("|%d: %d\n", i, dep[i]);
		int qnt = n;
		int ans = 0;
		for (int i = 1; i <= n and qnt; i++) {
			for (int j = 1; j <= n; j++) {
// 				printf ("%d: %d\n", j, dep[j]);
				if (dep[j] == 0) {
					qnt--;
					now.push_back (j);
					dep[j] = -1;
				}
			}
			while (!now.empty()) {
				for (int v : adj[now.back()])
					dep[v]--;
				now.pop_back ();
			}
			++ans;
		}
		
		if (qnt)
			printf ("-1\n");
		else
			printf ("%d\n", ans);
	}

	return 0;
}
