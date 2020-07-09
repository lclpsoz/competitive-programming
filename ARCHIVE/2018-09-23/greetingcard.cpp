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

const ll MOD = 1;
ll mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

map<ll, set<ll>> mp;
vector<pii> vec;
ll adj[][2] = {{0, 2018},
		{2018, 0},
		{1680, 1118},
		{1118, 1680}};

int main () {
  int n;
  scanf ("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf ("%d %d", &x, &y);
    mp[x].insert(y);
    vec.push_back ({x, y});
  }

  for (pii p : vec) {
    mp[p.x].erase (p.y);
    //printf ("%d %d\n", p.x, p.y);
    for (int i = 0; i < 4; i++)
      for (int x = -1; x <= 1; x += 2)
	for (int y = -1; y <= 1; y += 2) {
	  if ((adj[i][0] != 0 && adj[i][1] != 0) || (adj[i][0] == 0 && x == -1) || (adj[i][1] == 0 && y == -1)) {
	    //printf ("    %d %lld %lld\n", ans, p.x+adj[i][0]*x, p.y+adj[i][1]*y);
	      if (mp[p.x+adj[i][0]*x].count (p.y+adj[i][1]*y))
		++ans;
	    }
	}
  }

  printf ("%d\n", ans);
  
  
  return 0;
}
