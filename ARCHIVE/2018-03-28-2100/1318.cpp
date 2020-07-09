#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int arr[25000], ans;

int main ()
{
	while (scanf ("%d %d", &n, &m), n || m) {
		ans = 0;
		for (int i = 0; i < m; i++) {
			scanf ("%d", &x);
			arr[x]++;
			if (arr[x] == 2)
				ans++;
		}
		printf ("%d\n", ans);
		for (int i = 0; i <= n; i++)
				arr[i] = 0;
	}
	return 0;
}
