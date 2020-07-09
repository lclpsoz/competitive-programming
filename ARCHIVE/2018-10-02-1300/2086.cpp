#include <bits/stdc++.h>
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

const int N = 105;

int n, m, q;
int u, v, w, st, en;
int dist[N][N];

int main () {
  while (scanf ("%d %d", &n, &m), n || m) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
	if (i == j)
	  dist[i][j] = 0;
	else
	  dist[i][j] = 1e9;
    while (m--) {
      scanf ("%d %d %d", &u, &v, &w);
      dist[v][u] = dist[u][v] = min (dist[u][v], w);
    }
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	  dist[i][j] = min (dist[i][j], max (dist[i][k], dist[k][j]));
    
    scanf ("%d", &q);
    while (q--) {
      scanf ("%d %d", &st, &en);
      printf ("%d\n", dist[st][en]);
    }
  }
  
  return 0;
}
