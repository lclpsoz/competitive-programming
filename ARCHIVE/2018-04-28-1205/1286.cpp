#include <bits/stdc++.h>
using namespace std;

const int MAXN = 32;

typedef pair<long long, long long> pii;

int n, c;
long long tmp, qnt;
pii arr[MAXN];
long long maxi[MAXN];
long long ans;

int main ()
{
	while (scanf ("%d", &n), n) {
		scanf ("%d", &c);
		for (int i = 0; i < n; i++) {
			scanf ("%lld %lld", &tmp, &qnt);
			arr[i] = {tmp, qnt};
		}
		int i = 0, f, s;
		ans = 0;
		maxi[0] = 0;
		for (int i = 1; i < MAXN; i++)
			maxi[i] = -1;
		while (i < n) {
			f = arr[i].first;
			s = arr[i].second;
			for (int i = c; i-s >= 0 && i; i--) {
				if (maxi[(int)i-s] > -1) {
					maxi[i] = max (maxi[i], maxi[(int)i-s]+f);
					// printf ("%d ", maxi[i]);
				}
			}
			/*for (int i = 0; i <= c; i++)
				printf ("%lld ", maxi[i]);
			putchar ('\n');*/
			i++;
		}
		ans = 0;
		for (int i = 0; i < MAXN; i++)
			ans = max (ans, maxi[i]);
		printf ("%lld min.\n", ans);
	}

	return 0;
}
