#include <bits/stdc++.h>
using namespace std;

int n;
int a, e;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%dx%d", &a, &e);
			printf ("%dx", a*e);
			if (e > 2)
				printf ("%d", e-1);
			if (i < n-1) {
				printf (" + ");
				scanf (" + ");
			}
		}
		putchar ('\n');
	}

	return 0;
}
