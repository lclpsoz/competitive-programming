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

int n, m;
vector<int> rows, col;
vector<int> mat[110][110];

int pow2 (int v) {
  int r = 1;
  while (v--) r *= 2;
  return r;
}

int main () {
  scanf ("%d %d", &n, &m);
  int val = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf ("%d", &x);
    val ^= x;
    rows.push_back (x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf ("%d", &x);
    val ^= x;
    col.push_back (x);
  }

  if (val)
    printf ("NO\n");
  else {
    printf ("YES\n");
    for (int p = 0; p < 31; p++) {
      vector<int> r, c;
      for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	  mat[i][j].push_back (0);
      // Rows
      for (int i = 0; i < n; i++) {
	r.push_back (rows[i]&1);
	rows[i]>>=1;
      }
      // Columns
      for (int i = 0; i < m; i++) {
	c.push_back (col[i]&1);
	col[i] >>= 1;
      }

      // Process Rows
      for (int i = 0; i < n; i++) {
	int j = 0;
	if (r[i] == 1) {
	  bool test = false;
	  for (; j < m; j++)
	    if (c[j] == 1) {
	      r[i] = 0;
	      c[j] = 0;
	      test = true;
	      mat[i][j].back() = 1;
	      break;
	    }
	  // Find another row to match
	  if (!test) {
	    int zr = 0;
	    while (zr < m && c[zr] != 0)
	      ++zr;
	    j = i+1;
	    for (; j < n; j++)
	      if (r[j] == 1) {
		r[i] = r[j] = 0;
		mat[i][zr].back() = mat[j][zr].back() = 1;
		break;
	      }
	  }
	}
      }

      // Process Columns
      for (int i = 0; i < m; i++) {
	int j = 0;
	if (c[i] == 1) {
	  bool test = false;
	  for (; j < n; j++)
	    if (r[j] == 1) {
	      c[i] = 0;
	      r[j] = 0;
	      test = true;
	      mat[j][i].back() = 1;
	      break;
	    }
	  // Find another row to match
	  if (!test) {
	    int zr = 0;
	    while (zr < n && r[zr] != 0)
	      ++zr;
	    j = i+1;
	    for (; j < m; j++)
	      if (c[j] == 1) {
		c[i] = c[j] = 0;
		mat[zr][i].back() = mat[zr][j].back() = 1;
		break;
		
	      }
	  }
	}
      }

      /*
      for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++)
	  printf ("%d ", mat[i][j].back());
	putchar ('\n');
      }
      putchar ('\n');
      */

    }
    int matt[105][105];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
	int val = 0;
	for (int k = 0; k < len (mat[i][j]); k++) {
	  val += mat[i][j][k] * pow2(k);
	  //printf ("%d\n", val);
	}
	matt[i][j] = val;
	printf ("%d", val);
	if (j < m-1)
	  putchar (' ');
      }
      putchar ('\n');
    }

    /*
    for (int i = 0; i < n; i++) {
      int val = 0;
      for (int j = 0; j < m; j++)
	val ^= matt[i][j];
      printf ("%d: %d\n", i, val);
    }
    */
  }
  
  return 0;
}
