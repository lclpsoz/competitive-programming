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

const int MOD = 1e9+7;
int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int W = 15010;

int t;
int n, m, k, w;
int x;
int pdA[W], pdB[W];

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d %d %d", &n, &m, &k, &w);
      for (int i = 1; i <= w; i++)
	pdA[i] = pdB[i] = 0;
      pdA[0] = pdB[0] = 1;
      for (int i = 0; i < n; i++) {
	scanf ("%d", &x);
	for (int j = w; j >= x; j--)
	  if (pdA[j-x])
	    pdA[j] = mod (pdA[j] + pdA[j-x]);
      }
      for (int i = 0; i < m; i++) {
	scanf ("%d", &x);
	for (int j = w; j >= x; j--)
	  if (pdB[j-x])
	    pdB[j] = mod (pdB[j] + pdB[j-x]);
      }
      int ans = 0;
      for (int i = 0; i <= w; i++) {
	if (abs((w-i)-i) <= k)
	  ans = mod (ans+(1LL*pdA[i]*pdB[w-i]));
      }

      printf ("%d\n", ans);
  }
  
  return 0;
}
