#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int n, m;
long long arr[MAXN], x;

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		if (m > 1) {
			scanf ("%lld", &arr[0]);
			scanf ("%lld", &x);
			arr[1] = max (arr[0], x);
			for (int i = 2; i < m; i++) {
				scanf ("%lld", &x);
				arr[i] = max (arr[i-1], arr[i-2]+x);
			}
		}
		else if (m == 1) {
			scanf ("%lld", &arr[0]);
		}

		printf ("Case %d: ", i);
		if (m == 0)
			printf ("0\n");
		else
			printf ("%lld\n", arr[m-1]);
		for (int i = 0; i < m; i++)
			arr[i] = 0;
	}

	return 0;
}
