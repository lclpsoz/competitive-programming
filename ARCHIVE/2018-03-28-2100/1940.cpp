#include <bits/stdc++.h>
using namespace std;

int i, j;
int p, r, n;
int arr[510];
pair <int, int> ans;

int main ()
{
	scanf ("%d %d", &p, &r);
	for (i = 0; i < r; i++)
		for (j = 0; j < p; j++) {
			scanf ("%d", &n);
			arr[j] += n;
			if (arr[j] >= ans.second) {
				ans.first = j+1;
				ans.second = arr[j];
			}
		}
	printf ("%d\n", ans.first);
	return 0;
}
