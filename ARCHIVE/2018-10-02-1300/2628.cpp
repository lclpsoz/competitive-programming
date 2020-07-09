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

const int X = 1e5+10;
const int MASK = 1<<16;
const int N = 16;

int n, m;
int not_prime[X];
vector<int> caves;
int dist[105][105];
int dp[MASK][N];

int func (int mask, int p) {
  int &ret = dp[mask][p];
  if (ret != -1)
    return ret;
  if (mask+1 == 1<<len (caves))
    return ret = dist[caves[p]][n];
  ret = 1e9;
  for (int i = 0; i < len (caves); i++)
    if (!(1<<i & mask))
      ret = min (ret,
		 func (mask | 1<<i, i) + dist[caves[p]][caves[i]]);

  return ret;
}

int main () {
  // Sieve of Eratosthenes
  for (int i = 2; i*i < X; i++)
    if (!not_prime[i])
      for (int j = i*i; j < X; j+=i)
	not_prime[j] = true;
  
  while (scanf ("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= n+1; i++)
      for (int j = 1; j <= n+1; j++)
	if (i != j)
	  dist[i][j] = 1e9;
	else
	  dist[i][j] = 0;
    for (int i = 0; i < n; i++) { 
      int x;
      scanf ("%d", &x);
      if (!not_prime[x])
	caves.push_back (i+1);
    }
    ++n; // Considering pier!
    
    while (m--) {
      int u, v, w;
      scanf ("%d %d %d", &u, &v, &w);
      dist[u][v] = dist[v][u] = min (dist[u][v], w);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	  dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);

    // Hamiltonian Path
    memset (dp, -1, sizeof dp);
    int ans = 2e9;
    for (int i = 0; i < len (caves); i++)
      ans = min (ans, func (1<<i, i) + dist[n][caves[i]]);
    
    printf ("%d\n", ans);
      
    caves.clear();
  }
  
  return 0;
}
