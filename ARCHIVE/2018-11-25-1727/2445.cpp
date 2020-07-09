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

const int N = 1e5+10;

int n;
int a[N];

int main () {
  scanf ("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
    sum += a[i];
  }
  sort (a, a+n, greater<int>());
  
  for (int i = 0; i < n-2; i++) {
    sum -= a[i];
    if (sum > a[i]) {
      printf ("%d\n", n-i);
      return 0;
    }
  }
  printf ("0\n");
  
  return 0;
}
