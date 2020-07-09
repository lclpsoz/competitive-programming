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

const int N = 20;

int n;
int arr[N];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < 12; i++)
    scanf ("%d", &arr[i]);
  sort (arr, arr+12);

  int ans = 0;
  for (int i = 11; i >= 0; i--) {
    if (n <= 0) break;
    ++ans;
    n -= arr[i];
  }

  if (n > 0)
    printf ("-1\n");
  else
    printf ("%d\n", ans);

  return 0;
}
