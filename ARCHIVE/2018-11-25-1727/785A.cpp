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

int n;

map<string, int> mp = {{"Tetrahedron", 4},
		       {"Cube", 6},
		       {"Octahedron", 8},
		       {"Dodecahedron", 12},
		       {"Icosahedron", 20}};

int main () {
  string str;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    ans += mp[str];
  }

  cout << ans << '\n';

  return 0;
}
