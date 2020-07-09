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

ll mdc (ll a, ll b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

ll mmc (ll a, ll b) {
  return (a*b)/mdc (a, b);
}

int main () {
  int t, a, b;
  while (scanf ("%d %d %d", &t, &a, &b), t || a || b) {
    ll mc = mmc (a, b);
    vector<int> div;
    int sq = sqrtl (t);
    for (int i = 1; i <= sq; i++)
      if (t%i == 0) {
	div.push_back (i);
	int aux = t/i;
	if (aux != i)
	  div.push_back (aux);
      }
    
    vector<int> vec;
    for (int i : div)
      if (mmc (i, mc) == t)
	vec.push_back (i);

    sort (vec.begin(), vec.end());
    for (int i = 0; i < len (vec); i++) {
      if (i) putchar (' ');
      printf ("%d", vec[i]);
    }
    putchar ('\n');
  }

  return 0;
}
