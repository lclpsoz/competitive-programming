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

int n, t;

ll mdc (ll a, ll b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

ll mmc (ll a, ll b) {
  return (a*b)/mdc (a, b);
}

const int N = 1e5+10;

bool a[N];

int main () {
  while (scanf ("%d %d", &n, &t), n || t) {
    memset (a, 0, sizeof (a));
    ll m = 1;
    int x;
    for (int i = 0; i < n; i++) {
      scanf ("%d", &x);
      a[x] = true;
      m = mmc (m, x);
    }
    ll ans = -1;
    for (int i = 2; i <= t/2; i++)
      if (t%i == 0) {
	if (!a[i] && mmc (i, m) == t) {
	  ans = i;
	  break;
	}
      }
    if (!a[t] && ans == -1 && mmc (t, m) == t)
      ans = t;
    
    if (ans == -1)
      printf ("impossivel\n");
    else
      printf ("%lld\n", ans);
  }
  
  return 0;
}
