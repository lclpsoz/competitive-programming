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

ll n;
int q;

int main () {
  scanf ("%lld %d", &n, &q);
  while (q--) {
    ll x, y;
    scanf ("%lld %lld", &x, &y);
    ll pos = (x-1)*n + y;
    if (n&1) {
      if (pos&1)
	printf ("%lld\n", (pos+1)/2);
      else
	printf ("%lld\n", ((n)*1LL*(n) + 1)/2 + (pos/2));
    } else {
      ll st = (n*1LL*n)/2 + 1;
      ll stRow = (n/2)*1LL*(x-1);
      if (x&1) {
	if (y&1) {
	  stRow++;
	} else {
	  stRow += st;
	}
      } else {
	if (y&1) {
	  stRow += st;
	} else {
	  stRow++;
	}
      }
      printf ("%lld\n", stRow + (y-1)/2);
    }
  }

  return 0;
}
