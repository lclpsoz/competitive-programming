#include <stdio.h>

int n, i, j;
long long arr[120], ans[60], aux;
bool test;

int main ()
{
	arr[0] = 1;
	arr[1] = 1;
	for (i = 2; i < 91; i++)
		arr[i] = arr[i-1]+arr[i-2];
	for (i = 0, j = 0; i < 91; i++) {
		test = false;
		if (arr[i] % 3 == 0)
			test = true;
		else {
			aux = arr[i];
			while (!test && aux) {
				if (aux%10 == 3)
					test = true;
				else
					aux /= 10;
			}
		}
		if (test)
			ans[j++] = arr[i];
	}
	while (scanf ("%d", &n), n) {
		printf ("%lld\n", ans[n-1]);
	}
	return 0;
}
