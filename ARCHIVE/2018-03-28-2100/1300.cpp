#include <bits/stdc++.h>
using namespace std;

int a;

int main ()
{
	while (scanf ("%d", &a) != EOF) {
		if ((a > 180 || a < 0) || (a%6))
			printf ("N\n");
		else
			printf ("Y\n");
	}

	return 0;
}
