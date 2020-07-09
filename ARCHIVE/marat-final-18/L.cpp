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

const int MAXN = 1e5+100;

int q;
int mx[MAXN];
int bit[MAXN];
vector<int> vals[MAXN];
vector<pii> queries[MAXN];
map<pii, int> mp;
int ans[MAXN];

void add (int p, int v) {
  for (int i = p; i < MAXN; i+=i&-i)
    bit[i] += v;
}

int sum (int p) {
  int r = 0;
  for (int i = p; i > 0; i-=i&-i)
    r += bit[i];

  return r;
}

void sieve () {
  int i;
  for (i = 2; i < MAXN; i++)
    if (mx[i] == 0) {
      for (int j = i; j < MAXN; j+=i)
	mx[j] = i;
    }
}

int main () {
  sieve();
  for (int i = 2; i < MAXN; i++)
    vals[mx[i]].push_back (i);
  
  scanf ("%d", &q);
  int id = 0;
  for (int i = 0; i < q; i++) {
    int n, k;
    scanf ("%d %d", &n, &k);
    queries[k].push_back ({n, id});
    ++id;
  }
  
  for (int i = 2; i < MAXN; i++) {
    for (int v : vals[i])
      add (v, 1);
    for (pii p : queries[i])
      ans[p.y] = sum (p.x);
  }

  for (int i = 0; i < q; i++)
    printf ("%d\n", ans[i]);
  

  return 0;
}
