#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, m, k;
int a, b;
int homem[MAXN];
long long ans;

int main ()
{
	while (scanf ("%d %d %d", &n, &m, &k) != EOF) {
		for (int i = 0; i <= k; i++) homem[i] = 0;
		ans = 0;
		// Homens
		while (n--) {
			scanf ("%d", &a);
			homem[a%k]++;
		}
		while (m--) {
			scanf ("%d", &a);
			if (a%k == 0)
				ans += homem[0];
			else
				ans += homem[k-(a%k)];
			// printf (":%lld\n", ans);
		}

		printf ("%lld\n", ans);
	}

	return 0;
}
