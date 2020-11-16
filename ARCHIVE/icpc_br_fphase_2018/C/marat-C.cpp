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

int n, m, li;
int bit[N];

int sum (int p) {
  int r = 0;
  while (p >= 1) {
    r += bit[p];
    //printf ("  |%d: %d\n", p, r);
    p -= p&-p;
  }

  return r;
}

void add (int p, int v) {
  while (p <= li) {
    bit[p] += v;
    p += p&-p;
  }
}

vector<int> comp;
int id_comp (int x) {
  auto it = lower_bound (comp.begin(), comp.end(), x);
  return it-comp.begin()+1;
}

int main () {
  scanf ("%d %d", &n, &m);
  scanf ("%d %d", &n, &m);
  li = max (n, m)*2 + 6;
  ll ans = (n+1)*1LL*(m+1);

  vector<pii> vec;

  // Horizontal
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf ("%d %d", &x, &y);
    vec.push_back ({x, y});
    comp.push_back(x);
    comp.push_back(y);
  }
  sort (comp.begin(), comp.end());
  comp.resize(unique (comp.begin(), comp.end()) - comp.begin());
  
  sort (vec.begin(), vec.end(), greater<pii>());
  for (auto p : vec) {
    int x = id_comp (p.y);
    ans += sum (x);
    add (x, 1);
  }

  // Vertical
  vec.clear();
  comp.clear();
  n = m;
  memset (bit, 0, sizeof (int)*li);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf ("%d %d", &x, &y);
    vec.push_back ({x, y});
    comp.push_back(x);
    comp.push_back(y);
  }
  
  sort (comp.begin(), comp.end());
  comp.resize(unique (comp.begin(), comp.end()) - comp.begin());
  
  sort (vec.begin(), vec.end(), greater<pii>());
  for (auto p : vec) {
    int x = id_comp (p.y);
    ans += sum (x);
    add (x, 1);
  }

  printf ("%lld\n", ans);  
  
  return 0;
}
