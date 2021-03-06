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

const int N = 1005;

int n, tt;
int a[N];
int dp[N][N];


int main () {
  scanf ("%d", &tt);
  for (int i = 0; i < N; i++)
    dp[i][i] = 1;
  for (int t = 1; t <= tt; t++) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
      scanf ("%d", &a[i]);
    for (int k = 1; k < n; k++) {
      //printf ("%d\n", k);
      for (int i = k; i < n; i++) {
	//printf ("%d %d\n", i, i-k);
	if (a[i] == a[i-k]) {
	  //printf ("||%d\n", a[i]);
	  dp[i-k][i] = dp[i-k+1][i-1]+1;
	}
	else
	  dp[i-k][i] = min (dp[i-k+1][i], dp[i-k][i-1]) + 1;
      }
    }
    printf ("Caso #%d: %d\n", t, dp[0][n-1]);
  }
  
  return 0;
}
