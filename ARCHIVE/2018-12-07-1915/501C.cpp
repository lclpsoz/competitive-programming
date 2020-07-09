#include "bits/stdc++.h"
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

const int N = (1<<16)+100;

int n;
pii arr[N];
vector<pii> ans;

void solve (int v) {
  if (arr[v].x == 1) {
    arr[v].x--;
    int u = arr[v].y;
    ans.push_back ({v, u});
    arr[u].x--;
    arr[u].y ^= v;
    solve (u);
  }
}

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    int d, s;
    scanf ("%d %d", &d, &s);
    arr[i] = {d, s};
  }

  for (int i = 0; i < n; i++)
    solve (i);

  printf ("%d\n", len (ans));
  for (pii p : ans)
    printf ("%d %d\n", p.x, p.y);
  
  return 0;
}
