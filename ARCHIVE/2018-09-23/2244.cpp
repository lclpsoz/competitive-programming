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

const int MOD = 1e9 + 7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
int a1, b1, a2, b2;
vector<pair<pii, int>> f1, f2; // f1 is max, f2 is min.
map<int, pair<ld, ld>> mp;

int main () {
  scanf ("%d", &n);
  for (int i = 1; i <=  n; i++) {
    scanf ("%d %d %d %d", &a1, &b1, &a2, &b2);
    f1.push_back ({{a1, b1}, i});
    f2.push_back ({{a2, b2}, i});
  }
  sort (f1.begin(), f1.end());
  sort (f2.begin(), f2.end());
  
  return 0;
}
