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

const int N = 1e5+10;

int n, q;
int a[N];
set<int> vals[N];

int main () {
  scanf ("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &a[i]);
    vals[a[i]].insert (i);
  }

  int opt, l, r, p, w;
  while (q--) {
    scanf ("%d", &opt);
    if (opt == 1) {
      scanf ("%d %d", &p, &w);
      vals[a[p]].erase (p);
      a[p] = w;
      vals[w].insert (p);
    } else {
      scanf ("%d %d %d", &l, &r, &w);
      int dif = distance (vals[w].lower_bound (l), vals[w].upper_bound(r));
      //printf ("[%d]| ", dif);
      printf ("%d\n", (r-l+1)-dif);
    }
  }
  
  
  
  return 0;
}
