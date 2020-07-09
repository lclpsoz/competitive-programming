#include <stdio.h>

int n;
int x, st, acu, ans;

int main ()
{
  while (scanf ("%d", &n), n) {
    acu = ans = 0;
    st = 0;
    int i = 0;
    for (; i < n; i++) {
      scanf ("%d", &x);
      if (x == 1)
	break;
      st++;
    }
    i++;
    for (; i < n; i++) {
      scanf ("%d", &x);
      if (x == 0)
	++acu;
      else {
	ans += acu/2;
	acu = 0;
      }
    }
    if (st == n)
      ans = (st+1)/2;
    else {
      st += acu;
      ans += st/2;
    }
    
    printf ("%d\n", ans);
  }

  return 0;
}
