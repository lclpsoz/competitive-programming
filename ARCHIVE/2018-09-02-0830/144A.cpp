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

int n;
int a[110];

int main () {
  scanf ("%d", &n);
  int pMax, pMin;
  int maxi = -1, mini = 1e9;
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &a[i]);
    if (a[i] > maxi) {
      maxi = a[i];
      pMax = i;
    }
    if (a[i] <= mini) {
      mini = a[i];
      pMin = i;
    }
  }

  int ans = (pMax-1) + (n-pMin);
  if (pMax > pMin)
    --ans;
  printf ("%d\n", ans);
  
  return 0;
}
