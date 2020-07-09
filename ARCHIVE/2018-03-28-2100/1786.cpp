#include <cstdio>

int main (void)
{
	int arr[14], i, aux1, aux2;
	while (scanf ("%1d", &arr[0]) != EOF) {
		aux1 = arr[0];
		aux2 = arr[0] * 9;
		for (i = 1; i <= 8; i++) {
			scanf ("%1d", &arr[i]);
			aux1 += arr[i] * (i+1);
			aux2 += arr[i] * (9-i);
		}
		aux1 %= 11;
		aux2 %= 11;
		if (aux1 == 10)
			aux1 = 0;
		if (aux2 == 10)
			aux2 = 0;
		for (i = 0; i < 9; i++) {
			if (i && !(i%3))
				putchar ('.');
			putchar (arr[i]+'0');
		}
		printf ("-%d%d\n", aux1, aux2);
	}
	return 0;
}
