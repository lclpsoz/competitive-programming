#include <stdio.h>

int n, q;
const int N = 1e5+10;

int main () {
  int t, x;
  int l, r, s;
  int ans;
  int pref[512][N];
  for (int i = 0; i < 512; i++)
    pref[i][0] = 0;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf ("%d", &x);
      int mask = 0;
      for (int j = 2; j <= 10; j++)
	if (x % j == 0)
	  mask |= (1 << (j-2));
      for (int p = 1; p < 512; p++) {
	pref[p][i] = pref[p][i-1];
	if (mask & p)
	  ++pref[p][i];
      }
    }

    while (q--) {
      ans = 0;
      scanf ("%d %d %d", &l, &r, &s);
      /*
      for (int i = 0; i <= r; i++)
	printf ("%d ", pref[(s>>1)][i]);
      putchar ('\n');
      */
      if (s&1)
	ans = r-l+1;
      else {
	s >>= 1;
	ans = pref[s][r] - pref[s][l-1];
      }
      printf ("%d\n", ans);
    }
  }
  
  return 0;
}
