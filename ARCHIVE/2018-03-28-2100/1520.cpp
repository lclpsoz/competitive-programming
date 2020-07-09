#include <bits/stdc++.h>
using namespace std;

int n, ans, l, r, x;
int i, j;
int arr[105];

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf ("%d %d", &l, &r);
			for (j = l; j <= r;j++)
				arr[j]++;
		}
		scanf ("%d", &x);
		ans = -1;
		if (arr[x]) {
			ans = 0;
			for (i = 1; i < x; i++)
				ans += arr[i];
		}
		if (ans > -1)
			printf ("%d found from %d to %d\n", x, ans, ans+arr[x]-1);
		else
			printf ("%d not found\n", x);
		for (i = 0; i < 102; i++)
			arr[i] = 0;
	}
	return 0;
}
