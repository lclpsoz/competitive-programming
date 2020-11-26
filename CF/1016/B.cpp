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

const int N = 1e3+100;

int n, m, q;
string base, sub;
int bit[N];

void add (int p, int v) {
  for (int i = p; i < N; i+=i&-i)
    bit[i] += v;
}

int sum (int p) {
  int r = 0;
  for (int i = p; i >= 1; i-=i&-i)
    r += bit[i];

  return r;
}

int main () {
  ios::sync_with_stdio (false);
  cin.tie (0);

  cin >> n >> m >> q;
  cin >> base >> sub;

  if (len (sub) > len (base))
    while (q--)
      cout << "0\n";
  else {
    for (int i = 0; i < len (base)-len(sub)+1; i++) {
      bool test = true;
      for (int j = 0; j < len (sub); j++)
	if (base[j+i] != sub[j]) test = false;
      if (test) {
	add (i+1, 1);
	//cout << i+1 << '\n';
      }
      //cout << test << '\n';
    }
      
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (r-l+1 < len (sub))
	cout << 0 << '\n';
      else
	cout << sum (r-len(sub)+1) - sum (l-1) << '\n';
    }
  }

  return 0;
}
