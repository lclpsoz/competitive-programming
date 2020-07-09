#include <stdio.h>

const int N = 1e7+10;

int n;
int arr[N];
int ans[101010];
int r;

int main () {
  scanf ("%d", &n);
  arr[1] = 1;
  if (n == 1) {
    printf ("2\n");
    printf ("1 2\n");
  } else {
    for (int i = 2; i < N; i++) {
      arr[i] += i-1;
      for (int j = i+i; j < N; j += i) --arr[j];
      if (arr[i] == n) {
	ans[r] = i;
	++r;
      }
    }
    printf ("%d\n", r);
    for (int i = 0; i < r; i++)
      printf ("%d ", ans[r]);
  }
  
  
  return 0;
}
