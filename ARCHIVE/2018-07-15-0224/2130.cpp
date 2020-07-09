#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
int dist[105][105][105];

int main () {
  int u, v, w;
  int c, t;
  int ins = 0;
  while (scanf ("%d %d", &n, &m) != EOF) {
    // Clear dist
    for (int i = 0; i <= n; i++)
      for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++) {
	  dist[i][j][k] = INF;
	  if (j == k)
	    dist[i][j][k] = 0;
	}

    // Read edges
    while (m--) {
      scanf ("%d %d %d", &u, &v, &w);
      dist[0][u][v] = min (dist[0][u][v], w);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	  dist[k][i][j] = min (dist[k-1][i][j],
			       dist[k-1][i][k]+dist[k-1][k][j]);

    // Answer queries
    printf ("Instancia %d\n", ++ins);
    scanf ("%d", &c);
    while (c--) {
      scanf ("%d %d %d", &u, &v, &t);
      printf ("%d\n", dist[t][u][v] == INF ? -1 : dist[t][u][v]);
    }
    /*for (int k = 0; k <= n; k++) {
      printf ("---------- %02d ----------\n", k);
      for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
      printf ("%2d ", dist[k][i][j] == INF ? -1 : dist[k][i][j]);
      putchar ('\n');
      }
      }*/
    putchar ('\n');
  }
  
  return 0;
}
