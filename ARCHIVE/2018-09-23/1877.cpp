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

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, k;
int a[1010];

int main () {
  scanf ("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf ("%d", &a[i]);

  int picos = 0;
  for (int i = 1; i < n-1; i++)
    if (a[i-1] < a[i] && a[i] > a[i+1])
      ++picos;
  if (picos == k)
    printf ("beautiful\n");
  else
    printf ("ugly\n");

  
  return 0;
}
