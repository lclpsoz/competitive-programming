#include <bits/stdc++.h>
using namespace std;

int n;
int arr[110];

int main ()
{
	scanf ("%d", &n);
	int x; int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		ans += abs(x);
	}

	printf ("%d\n", ans);

	return 0;
}
