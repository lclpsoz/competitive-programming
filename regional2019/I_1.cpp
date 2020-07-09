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

const int INF = 1E9 + 10;
const int N = 404;

int n, r, q;
int cold[N][N][N], hot[N][N][N];
vector<pii> allTemps;
int tempIdx[N], temp[N];

int main () {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cold[i][j][k] = hot[i][j][k] = INF;
	scanf ("%d %d ", &n, &r);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf (" %d", &x);
		temp[i] = x;
		allTemps.push_back ({x, i});
	}
	sort (allTemps.begin(), allTemps.end());
	vector<int> comp;
	for (pii p : allTemps)
		comp.push_back (p.x);
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

	while (r--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		// int posU = (lower_bound (allTemps.begin(), allTemps.end(), make_pair(temp[u], u)) - allTemps.begin()) + 1;
		// int posV = (lower_bound (allTemps.begin(), allTemps.end(), make_pair(temp[v], v)) - allTemps.begin()) + 1;
		// printf (" u = %d, v = %d, posU = %d, posV = %d, w = %d\n", u, v, posU, posV, w);
		cold[v][u][1] = w;
		cold[u][v][1] = w;
		hot[u][v][n] = w;
		hot[v][u][n] = w;
	}

	for (int k = 1; k <= n; k++) {
		int v = allTemps[k-1].y;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cold[i][j][k] = min (cold[i][j][k], cold[i][j][k-1]);
		// printf( "________ %d, v = %d _______\n", k, v);
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++)
		// 		printf ("%3d%c", cold[i][j][k] == INF ? -1 : cold[i][j][k], " \n"[j==n]);
		// printf ("__________\n");
		// for (int j = 1; j <= n; j++)
		// 	for (int i = 1; i <= n; i++) {
		// 		cold[i][v][k] = min (cold[i][v][k], cold[i][j][k] + cold[j][v][k]);
		// 		cold[v][i][k] = min (cold[v][i][k], cold[v][j][k] + cold[j][i][k]);
		// 	}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cold[i][j][k] = min (cold[i][j][k], cold[i][v][k] + cold[v][j][k]);
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++)
		// 		printf ("%3d%c", cold[i][j][k] == INF ? -1 : cold[i][j][k], " \n"[j==n]);
		// printf ("__________\n");
		// printf ("__________\n");
	}

	for (int k = n; k >= 1; k--) {
		int v = allTemps[k-1].y;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				hot[i][j][k] = min (hot[i][j][k], hot[i][j][k+1]);
		// printf( "________ %d, v = %d _______\n", k, v);
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++)
		// 		printf ("%3d%c", hot[i][j][k] == INF ? -1 : hot[i][j][k], " \n"[j==n]);
		// printf ("__________\n");
		// for (int j = 1; j <= n; j++)
		// 	for (int i = 1; i <= n; i++) {
		// 		hot[i][v][k] = min (hot[i][v][k], hot[i][j][k] + hot[j][v][k]);
		// 		hot[v][i][k] = min (hot[v][i][k], hot[v][j][k] + hot[j][i][k]);
		// 	}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				hot[i][j][k] = min (hot[i][j][k], hot[i][v][k] + hot[v][j][k]);
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++)
		// 		printf ("%3d%c", hot[i][j][k] == INF ? -1 : hot[i][j][k], " \n"[j==n]);
		// printf ("__________\n");
		// printf ("__________\n");
	}

	scanf ("%d", &q);
	while (q--) {
		int u, v, k, t;
		scanf ("%d %d %d %d", &u, &v, &k, &t);
		if (t==0) {
			--k;
			int tmp = comp[min (len (comp)-1, k)];
			int idx = (upper_bound (allTemps.begin(), allTemps.end(), make_pair (tmp, 1010)) - allTemps.begin());
			int &now = cold[u][v][idx];
			if (now >= INF)
				printf ("-1\n");
			else
				printf ("%d\n", now);
		} else {
			int tmp = comp[max (0, len(comp)-k)];
			int idx = (lower_bound (allTemps.begin(), allTemps.end(), make_pair (tmp, 0)) - allTemps.begin()) + 1;
			int &now = hot[u][v][idx];
			// printf ("idx = %d\n", idx);
			if (now >= INF)
				printf ("-1\n");
			else
				printf ("%d\n", now);
		}
	}

	return 0;
}
