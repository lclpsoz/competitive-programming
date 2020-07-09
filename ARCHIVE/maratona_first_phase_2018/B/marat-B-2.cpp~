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

int mat[N][N];

void dist (int x, int y, int k) {
  //printf ("%d %d\n", x, y);
  mat[x][y] = -1;
  for (int i = y+1; i < N; i++)
    if (mat[x][i] == -1)
      mat[x][i] = k;
  for (int i = x+1; i < N; i++)
    if (mat[i][y] == -1)
      mat[i][y] = k;
  for (int i = x+1, j = y+1; i < N && j < N; i++, j++)
    if (mat[i][j] == -1)
      mat[i][j] = k;
}

int main () {
  memset (mat, -1, sizeof (mat));
  for (int i = 0; i < N; i++)
    mat[i][i] = mat[i][0] = mat[0][i] = 0;

  int col = 0, lin;
  for (int k = 1; k < N; k++) {
    ++col;
    for (int i = 0; i < N && col < N; i++) {
      if (mat[i][col] == -1) {
	lin = i;
	break;
      }
      if (i == N-1) {
	i = 0;
	++col;
      }
    }
    if (col == N)
      break;
    dist (lin, col, 1);    
  }

  int n, x, y;
  scanf ("%d", &n);

  int qnt_neg = 0;
  int qnt_out = 0;
  while (n--) {
    scanf ("%d %d", &x, &y);
    if (x == y) {
      printf ("Y\n");
      return 0;
    } else if (mat[x][y] == -1)
      ++qnt_neg;
    else
      ++qnt_out;
  }
  printf ("%d %d\n", qnt_neg, qnt_out);
  if (qnt_out % 2 == 0)
    printf ("Y\n");
  else
    printf ("N\n");


  printf ("  |");
  for (int i = 0; i < 30; i++)
    printf ("%2d|", i);
  putchar ('\n');
  for (int i = 0; i < 30; i++) {
    printf ("%2d|", i);
    for (int j = 0; j < 30; j++)
      printf ("%*d|", 2, mat[i][j]);
    putchar ('\n');
  }
  putchar ('\n');
  
  
  return 0;
}
