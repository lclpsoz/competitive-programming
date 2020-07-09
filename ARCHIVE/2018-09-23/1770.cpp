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

const int M = 110;

int m, k;
int a[M];
bool b[M];

int main () {
  while (scanf ("%d %d", &m, &k) != EOF) {
    memset (b, 0, sizeof (bool) * (m+5));
    int aux = m;
    for (int i = 1; i <= m; i++)
      scanf ("%d", &a[i]);
    int acu = 0, x;
    for (int i = 0; i < k; i++) {
      scanf ("%d", &x);
      if (aux) {
	if (!b[x]) {
	  b[x] = true;
	  aux--;
	}
	acu += a[x];
      }
    }
    if (!aux)
      printf ("%d\n", acu);
    else
      printf ("%d\n", -1);
  }
  
  return 0;
}
