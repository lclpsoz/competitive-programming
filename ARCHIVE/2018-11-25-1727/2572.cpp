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

const int N = 2e5+10;

int a[N];
vector<int> tree[4*N];

void build (int p, int tl, int tr) {
  // printf ("%d %d %d\n", p, tl, tr);
  if (tl == tr) {
    tree[p].push_back (a[tl]);
    return;
  }
  
  int md = (tl+tr)/2;
  build (2*p, tl, md);
  build (2*p + 1, md+1, tr);

  int aux = 2*p;
  for (int x : tree[aux])
    tree[p].push_back (x);
  ++aux;
  for (int x : tree[aux])
    tree[p].push_back (x);
  sort (tree[p].begin(), tree[p].end(), greater<int>());
  aux = len (tree[p])-40;
  while (aux-- > 0)
    tree[p].pop_back();
}

void qry (int p, int tl, int tr, int l, int r, vector<int> &vec) {
  if (l <= tl && tr <= r) {
    for (int x : tree[p])
      vec.push_back (x);
    return;
  }

  int md = (tl+tr)/2;
  if (l <= md)
    qry (2*p, tl, md, l, r, vec);
  if (md < r)
    qry (2*p+1, md+1, tr, l, r, vec);
}

int main () {
  int n, k, r;
  scanf ("%d %d %d", &n, &k, &r);

  for (int i = 1; i <= n; i++)
    scanf ("%d", &a[i]);

  build (1, 1, n);

  while (r--) {
    int esq, dir;
    scanf ("%d %d", &esq, &dir);
    vector<int> vec;
    qry (1, 1, n, esq, dir, vec);
    sort (vec.begin(), vec.end(), greater<int>());
    int ans = 1;
    if (vec[0] == 0)
      printf ("0\n");
    else {
      for (int i = 0; i < len (vec) && i < k && vec[i]; i++)
	ans = mod (ans*1LL*vec[i]);
      printf ("%d\n", ans);
    }
  }
  
  return 0;
}
