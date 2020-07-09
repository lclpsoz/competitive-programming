#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n;
int arr1[MAXN];
int arr2[MAXN];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr1[i]);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr2[i]);

	sort (arr1, arr1+n);
	sort (arr2, arr2+n);
	arr1[n] = 1e9;
	arr2[n] = -1;
	int p = 0;
	int ans = 0;
	for (int i = 0; i < n && p < n; i++) {
		while (p < n && arr1[i] >= arr2[p])
			p++;
		if (p < n && arr1[i] < arr2[p]) {
			p++;
			ans++;
		}
	}

	printf ("%d\n", ans);

	return 0;
}
