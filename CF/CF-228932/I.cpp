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

const int N = 205;

int lin, col, n;
int mat[N][N];
int dist[N][N];
vector<int> path[N][N];

int main () {
  scanf ("%d %d %d", &lin, &col, &n);
  for (int i = 1; i <= lin; i++)
    for (int j = 1; j <= col; j++)
      scanf ("%d", &mat[i][j]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf ("%d", &dist[i][j]);
      if (i != j)
	path[i][j].push_back (j);
    }

  // Floyd-Warshall
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	if (dist[i][j] > dist[i][k]+dist[k][j]) {
	  dist[i][j] = dist[i][k]+dist[k][j];
	  path[i][j].clear();
	  for (int x : path[i][k])
	    path[i][j].push_back (x);
	  for (int x : path[k][j])
	    path[i][j].push_back (x);
	}

  int valAns = 1e9;
  vector<pair<pii, int>> ans;
  for (int k = 1; k <= n; k++) {
    int valNow = 0;
    vector<pair<pii, int>> now;
    for (int i = 1; i <= lin; i++)
      for (int j = 1; j <= col; j++)
	if (mat[i][j] != k) {
	  valNow += dist[mat[i][j]][k];
	  for (int x : path[mat[i][j]][k])
	    now.push_back ({{i, j}, x});
	}
    if (valNow < valAns) {
      valAns = valNow;
      ans.swap (now);
    }
  }
  printf ("%d %d\n", valAns, len (ans));
  for (auto p : ans)
    printf ("%d %d %d\n", p.x.x, p.x.y, p.y);
  
  return 0;
}
