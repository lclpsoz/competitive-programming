#include <bits/stdc++.h>
using namespace std;

int n;
int x;
bool arr[100100];

int main ()
{
	while (scanf ("%d", &n) != EOF)  {
		for (int i = 0; i < n-1; i++) {
			scanf ("%d", &x);
			arr[x] = true;
		}
		int ans;
		for (int i = 1; i <= n; i++) {
			// printf ("%d: %d\n", i, arr[i]);
			if (!arr[i])
				ans = i;
			else
				arr[i] = false;
		}
		printf ("%d\n", ans);
	}

	return 0;
}
