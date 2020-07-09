#include <bits/stdc++.h>
using namespace std;

int x;

int main ()
{
	int i = 0;
	while (scanf ("%d", &x), x != -1)
		printf ("Experiment %d: %d full cycle(s)\n", ++i, x/2);

	return 0;
}
