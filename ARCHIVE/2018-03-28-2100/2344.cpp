#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	scanf ("%d", &n);
	if (n == 0)
		printf ("E\n");
	else if (n > 0 && n < 36)
		printf ("D\n");
	else if (n > 35 && n < 61)
		printf ("C\n");
	else if (n > 60 && n < 86)
		printf ("B\n");
	else
		printf("A\n");

	return 0;
}
