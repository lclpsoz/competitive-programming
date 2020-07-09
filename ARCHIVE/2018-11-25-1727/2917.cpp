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

const int N = 1e6+10;

int n, x;
int vec[N];

int main () {
  while (scanf ("%d", &n) != EOF) {
    n*=10;
    int total = 0;
    for (int i = 0; i < n; i++)
      scanf ("%d", &vec[i]);

    int mx = 0;
    int ans = 0;
    int p = 0;
    for (int i = 0, j = 0; i < 2*n; i++, j++) {
      if (j == n)
	j = 0;
      mx += vec[j];
      if (vec[j] > mx) {
	mx = vec[j];
	p = i;
      }
      if (i-p == n)
	mx -= vec[p++];
      //printf ("|%d\n", mx);
      ans = max (ans, mx);
    }

    printf ("%d\n", ans);
  }

  return 0;
}
