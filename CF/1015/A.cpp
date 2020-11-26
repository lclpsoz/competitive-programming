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

const int N = 110;

int n, m;
int l, r;
bool arr[N];

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &l, &r);
    for (int j = l; j <= r; j++)
      arr[j] = true;
  }

  vector<int> vec;
  for (int i = 1; i <= m; i++)
    if (arr[i] == false)
      vec.push_back (i);
  printf ("%d\n", len (vec));
  for (int z : vec)
    printf ("%d ", z);
  
  return 0;
}
