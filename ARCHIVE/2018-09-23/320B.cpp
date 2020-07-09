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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
vector<pii> all;
vector<int> adj[110];
bool vis[110];

bool dfs (int v, int y) {
  if (vis[v])
    return false;
  vis[v] = true;
  if (v == y)
    return true;
  for (int u : adj[v])
    if (dfs (u, y))
      return true;
  return false;
}

int main () {
  scanf ("%d", &n);
  int opt, l, r;
  while (n--) {
    scanf ("%d %d %d", &opt, &l, &r);
    if (opt == 1) {
      int sz = all.size();
      for (int i = 0; i < sz; i++) {
	pii v = all[i];
	if ((v.x < l && l < v.y) || (v.x < r && r < v.y))
	  adj[sz].push_back (i);
	if ((l < v.x && v.x < r) || (l < v.y && v.y < r))
	  adj[i].push_back (sz);
      }
      all.push_back ({l, r});
    } else {
      memset (vis, 0, sizeof (vis));
      printf ("%s\n", dfs (l-1, r-1) ? "YES" : "NO");
    }
  }
  
  return 0;
}
