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

int n, k;

int main () {
  scanf ("%d %d", &n, &k);
  k = k*2 + 1;
  if (n%k == 0) {
    printf ("%d\n", n/k);
    for (int i = (k/2)+1; i <= n; i+=k)
      printf ("%d ", i);
    putchar ('\n');
  }
  else {
    printf ("%d\n", (n/k)+1);
    int st = max (1, (k/2)+1 - k + (n%k));
    for (int i = st; i <= n; i+=k)
      printf ("%d ", i);
    putchar ('\n');
  }
  
  return 0;
}
