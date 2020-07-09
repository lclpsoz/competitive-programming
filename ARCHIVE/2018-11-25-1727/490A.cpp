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
vector<int> arr[5];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf ("%d", &x);
    arr[x-1].push_back (i);
  }
  
  int w = min (len (arr[0]), min (len (arr[1]), len (arr[2])));
  printf ("%d\n", w);
  while (w--) {
    printf ("%d %d %d\n", arr[0].back(), arr[1].back(), arr[2].back());
    arr[0].pop_back();
    arr[1].pop_back();
    arr[2].pop_back();
  }
  
  return 0;
}
