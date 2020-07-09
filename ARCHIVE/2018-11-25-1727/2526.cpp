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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6+10;

int n;
int qnt[N];
ll tree[N];
int a[N];

void add (ll *bit, int p, ll v) {
  for (;p <= n; p += p&-p)
    bit[p] += v;
}

void add (int *bit, int p, int v) {
  for (;p <= n; p += p&-p)
    bit[p] += v;
}

int sum (int *bit, int p) {
  int ret = 0;
  for (; p >= 1; p -= p&-p)
    ret += bit[p];
  return ret;
}

ll sum (ll *bit, int p) {
  ll ret = 0;
  for (; p >= 1; p -= p&-p)
    ret += bit[p];
  return ret;
}

int main () {
  while (scanf ("%d", &n) != EOF) {
    //printf ("n: %d\n", n);
    memset (qnt, 0, sizeof (int)*(n+5));
    memset (tree, 0, sizeof (ll)*(n+5));
    for (int i = 0; i < n; i++)
      scanf ("%d", &a[i]);
    ll aux;
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
      add (qnt, a[i], 1);
      ans += sum (tree, a[i]);
      //printf ("|%lld\n", ans);
      aux = sum (qnt, a[i]-1);
      //printf ("|aux: %d\n", aux);
      if (aux)
	add (tree, a[i], aux);
    }
    
    printf ("%lld\n", ans);
  }
  
  return 0;
}
