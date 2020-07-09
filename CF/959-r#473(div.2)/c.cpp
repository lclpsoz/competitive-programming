#include <bits/stdc++.h>
using namespace std;

int n;

int main ()
{
	scanf ("%d", &n);
	// WRONG CASE:
	if (n < 6)
		printf ("-1\n");
	else {
		printf ("1 2\n");
		printf ("2 3\n");
		printf ("2 4\n");
		for (int i = 5; i <= n; i++)
			printf ("1 %d\n", i);

	}

	// CORRECT CASE:
	int x = 1;
	for (int i = 2; i <= n; i++)
		printf ("1 %d\n", i);

	return 0;
}
