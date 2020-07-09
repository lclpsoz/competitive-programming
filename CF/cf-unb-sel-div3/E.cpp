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

int a, b, c;
int x;
map<int, int> mp;

int main () {
  scanf ("%d %d %d", &a, &b, &c);
  while (a--) {
    scanf ("%d", &x);
    mp[x]++;
  }
  while (b--) {
    scanf ("%d", &x);
    mp[x]++;
  }
  while (c--) {
    scanf ("%d", &x);
    mp[x]++;
  }
  vector<int> vec;
  for (auto p : mp)
    if (p.y == 3)
      vec.push_back (p.x);
  for (int z : vec)
    printf ("%d ", z);
  putchar ('\n');
  
  return 0;
}
