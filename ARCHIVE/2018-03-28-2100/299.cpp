#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr[60], ans;

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (arr[i] > arr[j])
					ans++;
		printf ("Optimal train swapping takes %d swaps.\n", ans);
		ans = 0;
	}
	return 0;
}
