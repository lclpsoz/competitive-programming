#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;

int t;
int n, c, m;
int arr[MAXN];

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &n, &c, &m);
		for (int i = 0; i < m; i++)
			scanf ("%d", &arr[i]);
		sort (arr, arr+m, greater<int>());
		long long ans = 0;
		for (int i = 0; i < m; i++) {
			if (i%c == 0)
				ans += 2*arr[i];
		}

		printf ("%lld\n", ans);
	}

	return 0;
}
