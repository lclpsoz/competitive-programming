#include <stdio.h>

short i, j, x;
bool ans[10010];

int main ()
{
	for (i = 0; i <= 100; i++) {
		x = 0;
		for (j = i; j <= 100; j++) {
			x = (i*i) + (j*j);
			if (x <= 10000)
				ans[x] = true;
			else
				break;
		}
	}
	while (scanf ("%hd", &x) != EOF) {
		if (x >= 0)
			ans[x] ? printf ("YES\n") : printf ("NO\n");
		else
			printf ("NO\n");
	}

	return 0;
}
