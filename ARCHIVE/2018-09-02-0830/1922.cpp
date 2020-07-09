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

int n, m;
int d, kd;
set<int> all;
multiset<pii> vec;
set<pii> rem;

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &d, &kd);
    vec.insert ({d, kd});
    for (int j = d; j <= kd; j += d)
      all.insert (j);
  }

  int ans = 0;
  while (m--) {
    int maxi = 0, choosen;
    for (int x : all) {
      int now = 0;
      for (pii p : vec)
	if (p.y >= x && x%p.x == 0)
	  ++now;
      if (now > maxi) {
	maxi = now;
	choosen = x;
      }
    }
    for (pii p : vec)
      if (p.y >= choosen && choosen%p.x == 0)
	rem.insert (p);
    for (pii p : rem)
      vec.erase (p);
    rem.clear();
    ans += maxi;
  }

  printf ("%d\n", ans);
 
  return 0;
}
