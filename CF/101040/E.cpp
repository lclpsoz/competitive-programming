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

const int N = 505;

int n;
ll dist[N][N];

int main () {
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf ("%lld", &dist[i][j]);
      if (dist[i][j] == -1)
	dist[i][j] = 1e18;
    }
  
  for (int i = 1; i <= n; i++)
    dist[i][i] = 1e18;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	dist[i][j] = min (dist[i][j],
			  dist[i][k]+dist[k][j]);

  
  ll ans = 1e18;
  int id = -1;
  for (int i = 1; i <= n; i++)
    if (dist[i][i] < ans) {
      ans = dist[i][i];
      id = i;
    }
  
  /*for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf ("%d ", dist[i][j]);
    putchar ('\n');
  }*/

  if (id == -1)
    printf ("-1\n");
  else
    printf ("%d %lld\n", id, ans);
    
  
  return 0;
}
