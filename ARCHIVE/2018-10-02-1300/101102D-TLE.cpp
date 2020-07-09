#include <stdio.h>

const int N = 1010;

int t;
int mat[N][N];

bool verif (int x, int y, int a, int b) {
  int v = mat[x][y];
  for (int i = x; i <= a; i++)
    for (int j = y; j <= b; j++)
      if (mat[i][j] != v)
	return false;
  return true;
}

int main () {
  int r, c;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++)
	scanf ("%d", &mat[i][j]);

    long long ans = 0;
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++)
	for (int k = i; k <= r; k++)
	  for (int l = j; l <= c; l++)
	    if (i == k && j == l)
	      ++ans;
	    else
	      ans += verif (i, j, k, l);
    
    printf ("%lld\n", ans);
  }
  
  return 0;
}
