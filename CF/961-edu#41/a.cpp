#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1050];
int ans;

int main ()
{
	scanf ("%d %d", &n, &m);
	int x;
	while (m--) {
		scanf ("%d", &x);
		arr[x]++;
	}
	ans = 1e9;
	for (int i = 1; i <= n; i++)
		ans = min (ans, arr[i]);
	printf ("%d\n", ans);

	return 0;
}
