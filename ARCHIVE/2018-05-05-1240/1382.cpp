#include <bits/stdc++.h>
const int MAXN = 1e4+10;

int n, m;
int ans;
int arr[MAXN];

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d", &m);
		for (int i = 1; i <= m; i++)
			scanf ("%d", &arr[i]);
		for (int i = 1; i <= m; i++)
			while (arr[i] != i) {
				std::swap (arr[i], arr[arr[i]]);
				ans++;
			}

		printf ("%d\n", ans);
		ans = 0;
	}
	return 0;
}
