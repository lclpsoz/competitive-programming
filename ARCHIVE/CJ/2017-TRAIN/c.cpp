#include <bits/stdc++.h>
using namespace std;

long long n, k, n1;
long long x, y;

void bin (int z) {
	for (int l = 64; l >= 0; l--)
		if ((1LL<<l&z)) putchar ('1');
		else putchar ('0');
	putchar ('\n');
}
int main ()
{
	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf ("Case #%d: ", i);
		scanf ("%lld %lld", &n, &k);
		if (k == 1) {
			printf ("%lld %lld\n", n/2, (n-1)/2);
		} else {
			k = n-k;
			// CASE == 1
			int e = 64-__builtin_clzll(n);


			// CASE > 1
			printf ("n: %lld\n", n);
			printf ("e: %d\n", e);
			for (int j = (e)-2; k > 0 && j >= 0; j--) {
				x = (n>>j)<<j;
				// printf ("x: ");
				// bin (x);
				// printf ("n: ");
				// bin (n);
				y = (n ^ x);
				// printf ("y: ");
				// bin (y);
				y = (~y)&((1LL<<(j))-1);
				// printf ("y: ");
				// bin (y);
				printf ("y: %lld\n", y);
				x>>=j;
				x--;
				k-=y;
				if (k > 0) {
					x++;
					y = abs((n^(x<<j))+1);
					printf ("y: %lld\n", y);
					k-=y;
				}
				printf ("x: %lld\tk: %lld\n", x, k);
			}
			printf ("%lld %lld\n", x/2, (x-1)/2);
			//}
		}
	}

	return 0;
}
