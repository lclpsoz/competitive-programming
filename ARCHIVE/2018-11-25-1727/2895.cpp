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

int a[3000], b[3000];
int pot[20];

void rec (int maxi, int p = 0, int acu = 0, int qnt = 0) {
  if (p >= maxi)
    return;
  if (abs (acu-pot[p]) <= 2048 && (qnt+1) < a[abs (acu-pot[p])])
    a[abs (acu-pot[p])] = qnt+1;
  if (abs (acu+pot[p]) <= 2048 && (qnt+1) < a[abs (acu+pot[p])])
    a[abs (acu+pot[p])] = qnt+1;
  rec (maxi, p+1, acu-pot[p], qnt+1);
  rec (maxi, p+1, acu, qnt);
  rec (maxi, p+1, acu+pot[p], qnt+1);
}

int main () {
  for (int i = 1; i <= 2048; i++)
    a[i] = 1e9;
  pot[0] = 1;
  for (int i = 1; i < 20; i++)
    pot[i] = pot[i-1]<<1;
  
  rec(13);
  int t, n;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    printf ("%d\n", a[n]);
  }

  return 0;
}
