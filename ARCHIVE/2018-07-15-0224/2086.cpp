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
int dist[102][102][102];
int maxi[102][102][102];

int main ()
{
  int v, u, w;
  while (scanf ("%d %d", &n, &m), n || m) {
    for (int k = 0; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
	  dist[k][i][j] = INF;
	  if (i == j)
	    dist[k][i][j] = 0;
	}
    while (m--) {
      scanf ("%d %d %d", &v, &u, &w);
      dist[0][v][u] = dist[0][u][v] = min (w, dist[0][v][u]);
      maxi[0][v][u] = maxi[0][u][v] = w;
    }
    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
	  int &v1 = dist[k-1][i][k];
	  int &v2 = dist[k-1][k][j];
	  int &v3 = dist[k-1][i][j];
	  if (v1+v2 < v3) {
	    dist[k][i][j] = v1+v2;
	    maxi[k][i][j] = max (maxi[k-1][i][k], maxi[k-1][k][j]);
	  } else if (v1+v2 > v3) {
	    dist[k][i][j] = v3;
	    maxi[k][i][j] = maxi[k-1][i][j];
	  } else {
	    int aa = max (maxi[k-1][i][k], maxi[k-1][k][j]);
	    maxi[k][i][j] = min (aa, maxi[k-1][i][j]);
	  }
	}
    int q;
    scanf ("%d", &q);
    while (q--) {
      scanf ("%d %d", &v, &u);
      printf ("%d\n", maxi[n][v][u]);
    }
  }
  return 0;
}
