#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, n, m, ans;
char c;

int main ()
{
	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf (" %c %d %d", &c, &m, &n);
		switch (c) {
			case 'r': m > n ? ans = n : ans = m;
					  break;
			case 'k': ans = (m / 2.0) * n;
					  break;
			case 'Q': if (m < n)
						  swap (m, n);
					  if (!(n & 1) && m == n)
						  ans = n-1;
					  else
						  ans = n;
					  break;
			case 'K': ans = ((n + 1) / 2) * ((m + 1) / 2);
					  break;

		}

		printf ("%d\n", ans);
	}
	return 0;
}
