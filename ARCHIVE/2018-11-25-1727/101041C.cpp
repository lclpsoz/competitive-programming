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
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;

int powMod (int b, int p) {
  int aux = 1;
  while (p) {
    if (p&1)
      aux = mod (b*1LL*aux);
    b = mod (b*1LL*b);
    p >>= 1;
  }
  
  return aux;
}

int invMod (int v) {
  return powMod (v, MOD-2);
}

int func () {
  int fatN, fatM, fatNM;
  int fat = 1;
  for (int i = 1; i <= (n+m); i++) {
    fat = mod (i*1LL*fat);
    if (i == n)
      fatN = fat;
    if (i == m)
      fatM = fat;
  }
  fatNM = fat;
  return mod (fatNM*1LL*invMod(mod(fatN*1LL*fatM)));
}

int main () {
  scanf ("%d %d", &n, &m);
  printf ("%d\n", func ());
  
  return 0;
}
