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

int n;
vector<int> vec;
int mi, mx;

int main () {
  mi = 2e9;
  mx = -2e9;
  scanf ("%d", &n);
  while (n--) {
    int x;
    scanf ("%d", &x);
    vec.push_back (x);
    mi = min (mi, x);
    mx = max (mx, x);
  }

  int ax;
  for (int i = 0; i < len (vec); i++) {
    ax = 2e9;
    if (i > 0)
      ax = vec[i]-vec[i-1];
    if (i < len (vec)-1)
      ax = min (ax, vec[i+1]-vec[i]);
    printf ("%d %d\n", ax,
	    max (abs (vec[i]-mx),
		 abs (vec[i]-mi) )
	    );
  }

  return 0;
}
