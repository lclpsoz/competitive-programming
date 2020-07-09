#include <stdio.h>

int i;
int ar[8], n, count;

int main (void){

	ar[0] = 1;
	for (i = 1; i < 8; i++)
		ar[i] = ar[i - 1] * (i + 1);

	scanf("%d", &n);

	i = 7;
	while (n != 0 && i > 0){

		for (i; i >= 0 && n < ar[i]; i--);
		//printf("%d - %d = ", n, ar[i]);
		n -= ar[i];
		//printf("%d\n", n);
		count++;

	}

	printf("%d\n", count + n);

	return 0;
}
