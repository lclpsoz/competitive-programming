#include <bits/stdc++.h>
using namespace std;

int n;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		if (__builtin_popcount(n)&1)
			printf ("she loves me\n");
		else
			printf ("she loves not\n");
	}

	return 0;
}
