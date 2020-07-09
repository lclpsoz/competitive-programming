#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int main ()
{
	while (scanf ("%d %d %d", &n ,&m, &c), n || m || c) {
		// printf ("%d\n", (((n-8+1)/2)+c) * (((m-8+1)/2)+c));
		n -= 7;
		m -= 7;
		if (!(n%2) || !(m%2))
			printf ("%d\n", (n*m)/2);
		else if (n%2 && m%2)
			printf ("%d\n", ((n*m)/2)+c);
	}

	return 0;
}
