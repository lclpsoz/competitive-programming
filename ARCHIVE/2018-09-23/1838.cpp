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

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
int x, y;
vector<pii> vec;
int dp[3610];

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &x, &y);
    vec.push_back ({y, x});
  }
  sort (vec.begin(), vec.end());


  int ans = 0;
  
  for (auto p : vec) {
    int maxi = 0; 
    for (int i = 0; i <= p.y; i++)
      maxi = max (maxi, dp[i]);
    ans = max (ans, dp[p.x] = max (dp[p.x], maxi + p.x - p.y));
  }
  printf ("%d\n", ans);
  
  return 0;
}
