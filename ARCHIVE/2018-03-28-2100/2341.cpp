#include <bits/stdc++.h>
using namespace std;

int n, k, x;
int arr[2000];

int main ()
{
	scanf ("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		arr[x]++;
	}

	int ans = 1e9;
	for (int i = 1; i <= k; i++)
		ans = min (ans, arr[i]);

	printf ("%d\n", ans);

	return 0;
}
