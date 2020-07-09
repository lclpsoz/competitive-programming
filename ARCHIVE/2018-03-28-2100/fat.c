#include <stdio.h>

typedef long long unsigned llu;
llu n;
int arr[10000];

int main (void)
{
	n = 1;
	for (llu i = 1; i < 1000; i++) {
		n *= i;
		while (n % 10 == 0)
			n /= 10;
		n %= 1000000;
		arr[i] = n%10;

	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 10; j++)
			printf ("|%3d %d ", j + (10*i), arr[j + (10*i)]);
		printf ("\n");
	}
	return 0;
}
