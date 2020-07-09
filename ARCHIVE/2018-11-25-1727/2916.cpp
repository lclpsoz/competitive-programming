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

const int MOD = 1000000007;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6+10;

int n, k;
vector<int> arr (N);

int main () {
  while (scanf ("%d %d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++)
      scanf ("%d", &arr[i]);
    sort (arr.begin(), arr.begin()+n);
    k = n-k;
    int ans = 0;
    for (int i = k; i < n; i++) {
      ans = (ans + arr[i])%MOD;
    }
    
    printf ("%d\n", ans);
  }

  return 0;
}
