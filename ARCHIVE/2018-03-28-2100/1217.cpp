#include <bits/stdc++.h>
using namespace std;

int n, f, fTotal;
double v, vTotal;
char c;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%lf ", &v);
		vTotal += v;
		f = 1;
		while (c = getchar (), c != '\n' && c != EOF) {
			if (c == ' ')
				f++;
		}
		fTotal += f;
		printf ("day %d: %d kg\n", i+1, f);
	}
	printf ("%0.2lf kg by day\n", (double)fTotal/n);
	printf ("R$ %0.2lf by day\n", vTotal/n);
	return 0;
}
