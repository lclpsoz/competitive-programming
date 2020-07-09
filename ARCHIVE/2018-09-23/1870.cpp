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

int l, c, p;
int mat[12][12];



int main () {
  while (scanf ("%d %d %d", &l, &c, &p), l || c || p) {
    for (int i = 1; i <= l; i++)
      for (int j = 1; j <= c; j++)
	scanf ("%d", &mat[i][j]);
    int lin = 1;
    int x, y;
    bool boom = false;
    while (!boom && lin <= l) {
      //printf ("%d %d\n", lin, p);
      if (mat[lin][p] != 0) {
	boom = true;
	x = lin;
	y = p;
	break;
      }
      int esq, dir;
      esq = dir = 0;
      int v_l, v_r;
      for (int i = p-1; i >= 1; i--)
	if (mat[lin][i] != 0) {
	  esq = mat[lin][i];
	  v_l = i;
	  break;
	}
      for (int i = p+1; i <= c; i++)
	if (mat[lin][i] != 0) {
	  dir = mat[lin][i];
	  v_r = i;
	  break;
	}
      //printf ("esq: %d dir: %d\n", esq, dir);
      if (esq > dir) {
	p += esq-dir;
	if (p >= v_r) {
	  boom = true;
	  x = lin;
	  y = v_r;
	}
      } else if (esq < dir) {
	p -= dir-esq;
	if (p <= v_l) {
	  boom = true;
	  x = lin;
	  y = v_l;
	}
      }
      lin++;
    }
    if (boom)
      printf ("BOOM %d %d\n", x, y);
    else
      printf ("OUT %d\n", p);
  }
  
  return 0;
}
