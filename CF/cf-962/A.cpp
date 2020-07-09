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

const int N = 2e5+10;

int n;
int a[N];

int main () {
  scanf ("%d", &n);
  int total = 0; 
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
    total += a[i];
  }
  int acu = 0;
  for (int i = 0; i < n; i++) {
    acu += a[i];
    if (acu >= (total+1)/2) {
      printf ("%d\n", i+1);
      return 0;
    }
  }
    

  return 0;
}
