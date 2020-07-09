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

using pp = pair<int, ll>;

int n, m;
int x, y;
vector<pp> vals;
vector<int> ans;
ll aux[55];

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    vals.push_back ({x, 1LL<<m});
  }
  for (int i = 0; i < m; i++) {
    scanf ("%d", &x);
    aux[x] |= 1LL<<i;
  }
  for (int i = n-1; i > 0; i--) {
    for (int j = max (0, i-50); j < i; j++)
      if (vals[i].x - vals[j].x <= 50) {
	vals[j].y |= (aux[(vals[i].x-vals[j].x)]<<1 & vals[i].y)>>1;
      }
  }
  for (int i = 0; i < n; i++) {
    if (vals[i].y & 1)
      ans.push_back (vals[i].x);
  }
  printf ("%d\n", len (ans));
  for (int i = 0; i < len (ans); i++) {
    if (i) putchar (' ');
    printf ("%d", ans[i]);
  }
  putchar ('\n');
  
  return 0;
}
