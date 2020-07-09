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

const int N = 110;

int n, m;
int a[N];

int main () {
  scanf ("%d %d", &n, &m);
  while (m--) {
    int p, d;
    scanf ("%d %d", &p, &d);
    a[p] = 1;
    int p1 = p-d;
    while (p1 > 0) {
      a[p1] = 1;
      p1-=d;
    }
    p1 = p+d;
    while (p1 <= n) {
      a[p1] = 1;
      p1 += d;
    }
  }
  for (int i = 0; i < n; i++)
    printf ("%d\n", a[i+1]);
  
  
  return 0;
}
