#include <bits/stdc++.h>
using namespace std;

int a, b;

int main ()
{
	scanf ("%d %d", &a, &b);
	if (a < 0 || a > 432 || b < 0 || b > 468)
		printf ("fora\n");
	else
		printf ("dentro\n");
	return 0;
}
