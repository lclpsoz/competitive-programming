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

ll l, r;

ll mdc (ll a, ll b) {
  if (a == 0) return b;
  return mdc (b%a, a);
}

int main () {
  cin >> l >> r;
  for (ll a = l; a <= r; a++)
    for (ll b = a+1; b <= r; b++)
      for (ll c = b+1; c <= r; c++)
	if (mdc (a, b) == 1 && mdc (b, c) == 1 && mdc (a, c) != 1) {
	  cout << a << ' ' << b << ' ' << c << '\n';
	  return 0;
	}

  printf ("-1\n");
  
  return 0;
}
