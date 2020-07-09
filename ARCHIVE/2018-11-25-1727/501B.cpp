#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;gn

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
map<string, string> mp;
set<string> st;
string str1, str2;

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str1 >> str2;
    if (st.count (str1) == 0 && st.count (str2) == 0) {
      st.insert (str2);
    }
  }

  return 0;
}
