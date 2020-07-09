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

const int N = (1<<11) + 10;

int n, g;
int mini;
int mat[N][N], pref[N][N];

void compPref () {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      pref[i][j] = mat[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
}

// (x, y) -> upper-left
// (a, b) -> down-right
int sum (int x, int y, int a, int b) {
  return pref[a][b] - pref[a][y-1] - pref[x-1][b] + pref[x-1][y-1];
}

int main () {
  scanf ("%d %d", &n, &g);
  mini = 1000;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf ("%d", &mat[i][j]);
      mini = min (mini, mat[i][j]);
    }
  if (mini >= g) {// 1x1 valid
    printf ("%d\n", n*n);
    return 0;
  }

  compPref ();
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf ("%d ", pref[i][j]);
    putchar ('\n');
  }
  */
  for (int sz = 2; sz <= n; sz<<=1) {
    //printf ("sz: %d\n", sz);
    pii st = {1, 1};
    pii en = {sz, sz};
    bool test = true;
    while (test && en.x <= n) {
      //printf ("%d %d\n", st.x, en.x);
      while (test && en.y <= n) {
	//printf (" %d %d\n", en.x, en.y);
	int val = sum (st.x, st.y, en.x, en.y);
	//printf ("  val: %d\n", val);
	if (val < g)
	  test = false;
	en.y += sz;
	st.y += sz;
	//printf ("  |%d\n", en.y);
      }
      st.x += sz;
      st.y = 1;
      en.x += sz;
      en.y = sz;
    }
    if (test) {
      printf ("%d\n", (n/sz)*(n/sz));
      return 0;
    }
  }
  printf ("0\n");
  
  return 0;
}
