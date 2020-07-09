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

const int N = 2e5+10;

int n;
int ans;
int dp[N][4];
vector<int> adj[N];

int func (int v, int p, int d) {
  int &ret = dp[v][d];
  if (ret != -1)
    return ret;
  
  ret = 0;
  // Already connected
  if (d == 0) {
    for (int u : adj[v])
      if (u != p)
	ret += func (u, v, 1);
  }

  else if (d == 1) {
    // Connect now
    ret = 1;
    for (int u : adj[v])
      if (u != p)
	ret += func (u, v, 1);

    // Connect later
    int aux = 0;
    for (int u : adj[v])
      if (u != p)
	aux += func (u, v, 2);

    ret = min (ret, aux);
  }

  else {
    // Connect now
    ret = 1;
    for (int u : adj[v])
      if (u != p)
	ret += func (u, v, 1);

    // Connect ONE next
    for (int ativ : adj[v])
      if (ativ != p) {
	int aux = 1;
	for (int u : adj[v])
	  if (u != p) {
	    if (u == ativ)
	      aux += func (u, v, 0);
	    else
	      aux += func (u, v, 2);
	  }
	ret = min (aux, ret);
      }    
  }

  return ret;
}

int main () {
  memset (dp, -1, sizeof (dp));
  
  scanf ("%d", &n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf ("%d %d", &u, &v);
    adj[u].push_back (v);
    adj[v].push_back (u);
  }

  for (int v : adj[1])
    ans += func (v, 1, 0);
  /*
    for (int i = 1; i <= n+1; i++) {
    printf ("%2d: ", i);
    for (int j = 0; j < 4; j++)
    printf ("%2d|", dp[i][j]);
    putchar ('\n');
    }
  */
  
  
  printf ("%d\n", ans);
  
  return 0;
}
