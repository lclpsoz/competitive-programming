#include <bits/stdc++.h>
using namespace std;

int b, n, m;

int main ()
{
	while (scanf ("%d %d %d", &b, &n, &m) != EOF) {
		int x = n%m;
		int i, aux = 1;
		for (i = 0; i < m; i++) {
			if (aux == x)
				break;
			else
				aux  = (aux*b)%m;
		}
		printf ("%d\n", i == m ? -1 : i);
	}

	return 0;
}
