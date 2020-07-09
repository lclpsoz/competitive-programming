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

int n, x;
vector<int> vec;

int main () {
  scanf ("%d", &n);
  int total = 0;
  while (n--) {
    scanf ("%d", &x);
    total += x;
    vec.push_back (x);
  }
  sort (vec.begin(), vec.end(), greater<int>());
  
  if (cmp (vec[0], (ld)total*0.45) >= 0)
    printf ("1\n");
  else if (cmp (vec[0], (ld)total*0.4) >= 0 && cmp (vec[0], ((ld)total*0.1)+vec[1]) >= 0)
    printf ("1\n");
  else
    printf ("2\n");
  
  return 0;
}
