#include <bits/stdc++.h>
using namespace std;

int x, y, m;
int a, b;

int main ()
{
	while (scanf ("%d %d %d", &x, &y, &m) != EOF) {
		if (x < y)
			swap (x, y);
		while (m--) {
			scanf ("%d %d", &a, &b);
			if (a < b)
				swap (a, b);
			if (a <= x && b <= y)
				printf ("Sim\n");
			else
				printf ("Nao\n");
		}
	}

	return 0;
}
