#include <bits/stdc++.h>
using namespace std;

int n, base[35], arr[35], x;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			base[x-1] = i+1;
		}
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			arr[i] = base[x-1];
			//printf ("%d ", arr[i]);
		}
		//putchar ('\n');
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (arr[i] > arr[j])
					ans++;
		printf ("%d\n", ans);
	}
	return 0;
}
