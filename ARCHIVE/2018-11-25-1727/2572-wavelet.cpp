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

int pref[N]; // Amount of not 0's
vector<int> tree[4*N], vals[4*N];
vector<int> mapLeft[4*N], mapRight[4*N];

void buildWavelet (int p, int mini, int maxi) {
  vals[p] = 1;
  for (int i = 1; i < len (tree[p]); i++)
    vals[p] = mod (vals[p]*1LL*tree[p][i]);
  
  if (mini == maxi)
    return;
  int md = (l+r)/2;
  int l = 2*p;
  int r = 2*p+1;
  mapLeft[p] = vector<int>(len(tree[p]));
  mapRight[p] = vector<int>(len(tree[p]));
  tree[l].push_back (0);
  tree[r].push_back (0);
  for (int i = 1; i < len (tree[p]); i++) {
    if (tree[p][i] <= md) {
      mapLeft[p][i] = mapLeft[p][i-1]+1;
      tree[l].push_back (tree[p][i]);
    } else  {
      mapRight[p][i] = mapRight[p][i-1]+1;
      tree[r].push_back (tree[p][i]);
    }
  }

  buildWavelet (l, mini, md);
  buildWavelet (r, md+1, maxi);
}

int qry (int p, int mini, int maxi, int l, int r) {
  
}

int main () {
  int n, k, r;
  int mini, maxi;
  mini = 1e9;
  maxi = -1;
  scanf ("%d %d %d", &n, &k, &r);

  tree[1].push_back (0); // 1-indexed
  for (int i = 1; i <= n; i++) {
    int x;
    scanf ("%d", &x);
    pref[i] = pref[i-1];
    x ? ++pref[i] : x = 1;
    
    mini = min (x, mini);
    maxi = max (x, maxi);
    tree[1].push_back (x);
  }

  buildWavelet(1, mini, maxi);
  
  return 0;
}
