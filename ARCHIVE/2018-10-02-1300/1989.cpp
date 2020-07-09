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

const int N = 1e5+100;

int n, m;
int x;
ll ans, acu;

int main () {
  while (scanf ("%d %d", &n, &m), n != -1) {
    ans = acu = 0;
    for (int i = 0; i < n; i++) {
      scanf ("%d", &x);
      ans += acu + x*m;
      acu += x*m;
    }
    
    printf ("%lld\n", ans);
  }
  
  
  return 0;
}
