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

int n, m, l;
bool arr[1010];
vector<int> inter[1010];

int main () {
  scanf ("%d %d %d", &n, &m, &l);
  int x;
  for (int i = 0; i < l; i++) {
    scanf ("%d", &x);
    arr[x] = true;
  }

  int k;
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &k);
    while (k--) {
      scanf ("%d", &x);
      inter[i-1].push_back (x);
    }
  }

  for (int i = 0; i < 1e4; i++) {
    for (auto y : inter[i%n])
      arr[y] = !arr[y];
    bool check = true;
    for (int i = 1; i <= m; i++) {
      //printf ("%d ", arr[i]);
      if (arr[i]) {
	check = false;
	break;
      }
    }
    //putchar ('\n');
    if (check) {
      printf ("%d\n", i+1);
      return 0;
    }
  }
  printf ("%d\n", -1);

  
  
  return 0;
}
