#include <bits/stdc++.h>
using namespace std;

// -----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

// --------

int main () {
  int n;
  scanf("%d", &n);
  
  int sum = 0, mn = 1e9;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    sum += x;
    mn = min(mn, sum);
  }
  printf("%d\n", abs(min(mn, 0)));
  
  return 0;
}