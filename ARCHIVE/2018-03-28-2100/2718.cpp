#include <bits/stdc++.h>
using namespace std;

int n, ans, aux;
long long x;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &x);
		ans = aux = 0;
		while (x) {
			if (x&1)
				aux++;
			else {
				ans = max (aux, ans);
				aux = 0;
			}
			x >>= 1;
		}
		ans = max (aux, ans);
		printf ("%d\n", ans);
	}
	return 0;
}
