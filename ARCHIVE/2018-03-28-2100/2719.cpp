#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, maxi, x, aux, ans;
int i, j;

int main ()
{
	scanf ("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf ("%lld %lld", &m, &maxi);
		aux = 0;
		ans = 0;
		for (j = 0; j < m; j++) {
			scanf ("%lld", &x);
			aux -= x;
			if (aux < 0) {
				ans++;
				aux = maxi - x;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
