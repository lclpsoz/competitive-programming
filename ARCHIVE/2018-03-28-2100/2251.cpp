#include <bits/stdc++.h>
using namespace std;

int i;
int arr[32], x;

int main ()
{
	for (i = 1; i <= 30; i++) {
		x = 2;
		for (int j = 1; j < i; j++)
			x *= 2;
		arr[i] = x-1;
	}
	i = 0;
	while (scanf ("%d", &x), x) {
		printf ("Teste %d\n", ++i);
		printf ("%d\n\n", arr[x]);
	}
	return 0;
}
