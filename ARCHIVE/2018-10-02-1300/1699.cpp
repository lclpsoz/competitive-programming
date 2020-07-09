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

const int N = 1e6+10;

int n;
int ans;

int main () {
  ll x;
  while (scanf ("%d", &n), n) {
    ans = 0;
    while (n--) {
      scanf ("%lld", &x);
      int s = sqrtl (x);
      //printf ("%d\n", s);
      if (s*1LL*s == x)
	++ans;
    }
    
    printf ("%s\n", (ans&1 ? "Annie" : "Garen"));
  }
  
  return 0;
}
