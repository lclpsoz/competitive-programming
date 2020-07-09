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

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e7+10;

int n, k;
int adj[N];
int vis[N];

int func (int x) {
  if (vis[x] != -1)
    return vis[x];
  ll u = x&1 ? 3*x+1 : x/2;
  if (u > n) {
    adj[x] = -1;
    vis[x] = 1;
    return 1;
  }
  adj[x] = u;
  return vis[x] = func (u)+1;
}

int main () {
  scanf ("%d %d", &n, &k);
  memset (vis, -1, sizeof(int)*(n+1));
  if (n >= 4)
    vis[1] = 1e8;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += (func (i) >= k);
  printf ("%d\n", ans);
  
  return 0;
}
