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

const ll MOD = 1e12;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6+10;

int ans[N];

int main () {
  ll x = 1;
  ans[1] = 1;
  for (int i = 2; i < N; i++) {
    int aux = i;
    while (aux%10 == 0)
      aux /= 10;
    x = aux*x;
    //printf ("%lld\n", x);
    while (x%10 == 0)
      x /= 10;
    x %= MOD;
    ans[i] = x%10;
    //if (i < 20)
    //  printf ("%d: %lld\n", i, x);
  }

  //for (int i = 50000; i <= 50010; i++)
  //  printf ("%d: %d\n", i, ans[i]);

  int n;
  while (scanf ("%d", &n) != EOF)
    printf ("%d\n", ans[n]);
  
  return 0;
}
