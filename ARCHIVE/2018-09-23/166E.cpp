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

const int MOD = 1e9+7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
  int n;
  scanf ("%d", &n);
  ll zero = 0, zero_now;
  ll others = 1;
  for (int i = 2; i <= n; i++) {
    zero_now = 3*others;
    others = 2*others + zero;
    zero = zero_now;
    if (i%20 == 0) {
      zero = mod (zero);
      others = mod (others);
    }
  }
	
  printf ("%d\n", mod(zero));

  
  return 0;
}
