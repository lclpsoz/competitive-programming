#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[55];

int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 1; i <= n; i++)
			scanf ("%d", &arr[i]);
		scanf ("%d", &k);
		int i = arr[k];
		while (arr[i] != i)
			i = arr[i];
		printf ("%d\n", i);
	}

	return 0;
}
