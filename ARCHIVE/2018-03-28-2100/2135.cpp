#include <bits/stdc++.h>
using namespace std;

int n;

int main ()
{
	int ins = 1;
	int sum, x, ans;
	while (scanf ("%d", &n) != EOF) {
		sum = 0;
		ans = 100;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			if (x == sum && ans == 100)
				ans = x;
			sum += x;
		}
		printf ("Instancia %d\n", ins++);
		if (ans != 100)
			printf ("%d\n\n", ans);
		else
			printf ("nao achei\n\n");
	}

	return 0;
}
