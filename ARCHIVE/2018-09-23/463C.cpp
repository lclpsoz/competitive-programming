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

const int N = 2e3+10;

int mat[N][N];

int main () {
  int n;
  for (int i = 1; i <= n; i++)
    scanf ("%d", &mat[i][j]);
  pair<ll, ll> princ, sec;
  // Diagonal princ.
  for (int j = n; j >= 1; j--)
    for (int k = 0; j+k <= n; ++k)
      
  
  return 0;
}
