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

const int N = 1010;

int n, d;
vector<int> adj[N];
vector<pii> vec;
int vis[N];

int operator- (pii &a, pii &b) {
  int x = a.x-b.x;
  int y = a.y-b.y;
  return x*x + y*y;
}

void dfs (int v) {
  if (vis[v])
    return;
  vis[v] = true;
  for (int u : adj[v])
    dfs (u);
}

int main () {
  scanf ("%d %d", &n, &d);
  d *= d;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf ("%d %d", &x, &y);
    vec.push_back ({x, y});
  }
  for (int i = 0; i < len (vec); i++)
    for (int j = i+1; j < len (vec); j++)
      if ((vec[i]-vec[j]) <= d) {
	adj[i].push_back (j);
	adj[j].push_back (i);
      }

  dfs (0);
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      printf ("N\n");
      return 0;
    }
  printf ("S\n");
  
  return 0;
}
