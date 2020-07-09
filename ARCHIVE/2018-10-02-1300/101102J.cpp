#include <stdio.h>

int n, q;
const int N = 1e5+10;
int pref[512][N];
int simple[520];

int main () {
  for (int i = 1; i < 512; i++) {
    int ax = i;
    if (i&1) { // 2
      for (int j = 2; j < 10; j+=2)
	if (ax & (1<<j))
	  ax ^= 1<<j;
    }
    if ((i>>1)&1) { // 3
      if (ax & (1<<4))
	ax ^= (1<<4);
      if (ax & (1<<7))
	ax ^= (1<<7);
    }
    if ((i>>2)&1 && (ax & (1 << 6))) // 4
      ax ^= (1<<6);
    simple[i] = ax;
  }
  
  int t, x;
  int l, r, s;
  int ans;
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
	if (simple[p] != p)
	  continue;
	pref[p][i] = pref[p][i-1];
	if (mask & p)
	  ++pref[p][i];
      }
    }

    while (q--) {
      ans = 0;
      scanf ("%d %d %d", &l, &r, &s);
      if (s&1)
	ans = r-l+1;
      else {
	s >>= 1;
	s = simple[s];
	ans = pref[s][r] - pref[s][l-1];
      }
      printf ("%d\n", ans);
    }
  }
  
  return 0;
}
