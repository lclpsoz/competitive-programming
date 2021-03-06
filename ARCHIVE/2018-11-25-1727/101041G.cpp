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

const int MAXN = 1e6+10;

int z[MAXN];

void zfunction (string s) {
  int n = len (s);
  assert (s.size() < MAXN);
  fill (z, z+n, 0);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min (r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      ++z[i];
    if (i+z[i]-1 > r)
      l = i, r = i+z[i]-1;
  }
}

int func (string &str, int sz) {
  zfunction (str);
  int r = 0;
  for (int i = 1; i < len (str); i++)
    if (z[i] == sz) {
      ++r;
      i += sz-1;
    }

  return r;
}

int main () {
  cin.tie (0);
  ios::sync_with_stdio (false);
  string str;
  string music, p;
  int n;
  while (getline (cin, p), p != "EOF") {
    while (getline (cin, str) && len (str) != 0)
      music += str;
    string aux = p+"#"+music;
    int qnt = func (aux, len (p));
    int idx = -1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
      while (getline (cin, p) && len (p) == 0);
      music = "";
      while (getline (cin, str) && len (str))
	music += str;
      aux = p+"#"+music;
      int ax = func (aux, len (p));
      if (qnt < ax) {
	qnt = ax;
	idx = i;
      }
    }

    cout << idx << '\n';;
  }
  
  return 0;
}
