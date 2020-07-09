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

const int T = 2e6 + 10;

int n, m;
ll k, a[22][22];
ll ans;
vector<ll> vals1[22], vals2[22]; // 1 is (m, 1), 2 is (m-1, 2)... WITH TRIE

void dfs_left (int x, int y, ll val) {
  if (a[x][y] == -1)
    return;
  //printf ("%d %d %lld\n", x, y, val);
  if (x+y == (m+1)) {
    vals1[y].push_back (val);
    return;
  }
  
  dfs_left (x+1, y, val^a[x+1][y]);
  dfs_left (x, y+1, val^a[x][y+1]);
}

void dfs_right (int x, int y, ll val) {
  if (a[x][y] == -1)
    return;
  if ((x+y) == (m+1)) {
    vals2[y].push_back (val);
    return;
  }
  
  val^=a[x][y];
  dfs_right (x-1, y, val);
  dfs_right (x, y-1, val);
}

int main () {
  memset (a, -1,  sizeof (a));
  scanf ("%d %d %lld", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf ("%lld", &a[i][j]);

  dfs_left (1, 1, a[1][1]);

  /*
  for (int i = 1; i <= m; i++) {
    printf ("%2d: ", i);
    printf ("%d", len (vals[i]));
    //for (ll z : vals[i])
    //  printf ("%lld ", z);
    putchar ('\n');
  }
  */
  
  dfs_right (n, m, k);

  for (int i = 1; i <= m; i++) {
    vector<ll> v1 = vals1[i];
    vector<ll> v2 = vals2[i];
    //printf ("%d %d\n", len (v1), len (v2));
    sort (v1.begin(), v1.end());
    sort (v2.begin(), v2.end());
    //printf ("-- bye bye sort\n");
    // printf ("here\n");
    int l1, r1, l2, r2;
    l1 = r1 = l2 = r2 = 0;

    while (l1 < len (v1) && l2 < len (v2)) {
      //printf ("%d %d\n", l1, l2);
      while (l1 < len (v1) && v1[l1] < v2[l2])
	++l1;
      if (l1 == len (v1)) break;
      
      while (l2 < len (v2) && v2[l2] < v1[l1])
	++l2;
      if (l2 == len (v2)) break;
      //printf ("here\n");
      if (v1[l1] != v2[l2]) continue;

      // Only here because are equal!
      r1 = l1; r2 = l2;
      //printf ("hhere %d %d\n", r1, r2);
      while (r1+1 < len (v1) && v1[r1+1] == v1[r1])
	++r1;
      while (r2+1 < len (v2) && v2[r2+1] == v2[r2])
	++r2;
      ans += (r1-l1+1) * 1LL * (r2-l2+1);
      l1 = r1+1;
      l2 = r2+1;
    }
  }

  printf ("%lld\n", ans);
  
  return 0;
}
