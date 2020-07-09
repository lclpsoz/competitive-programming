#include <bits/stdc++.h>
using namespace std;

double n, cut;

int main ()
{
	while (scanf ("%lf", &n) != EOF) {
		scanf ("%lf", &cut);
		// printf ("%lf %lf\n", n, cut);
		if (((n-((int)n))) > cut)
			printf ("%d\n", (int)n+1);
		else
			printf ("%d\n", (int)n);
	}
	return 0;
}
