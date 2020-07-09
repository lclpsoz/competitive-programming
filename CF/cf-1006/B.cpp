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

int n, k;
int arr[2020];

int main () {
  scanf ("%d %d", &n, &k);
  vector<int> vec, ans, ori;
  for (int i = 0; i < n; i++) {
    int x;
    scanf ("%d", &x);
    vec.push_back (x);
    ori.push_back (x);
  }
  sort (vec.begin(), vec.end());
  int total = 0;
  while (k--) {
    arr[vec.back()]++;
    total += vec.back();
    vec.pop_back();
  }

  ans.push_back (-1);
  for (int i = 0; i < n; i++) {
    if (arr[ori[i]]) {
      arr[ori[i]]--;
      ans.push_back (i);
    }
  }

  printf ("%d\n", total);
  for (int i = 1; i < len(ans)-1; i++)
    printf ("%d ", ans[i]-ans[i-1]);
  printf ("%d\n", n-ans[len(ans)-2]-1);

  
  
  return 0;
}
