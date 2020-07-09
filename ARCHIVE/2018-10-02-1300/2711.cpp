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

const int N = 1e5+10;

int b, n, m;
bool arr[N];

int main () {
  while (scanf ("%d %d %d", &b, &n, &m) != EOF) {
    memset (arr, false, sizeof arr);
    n %= m;
    int ans = 0;
    int aux = 1;
    while ((aux >= N || !arr[aux]) && aux != n) {
      if (aux < N)
	arr[aux] = true;
      aux = (aux*1LL*b)%m;
      ++ans;
    }
    if (aux != n)
      printf ("-1\n");
    else
      printf ("%d\n", ans);
  }
  
  return 0;
}
