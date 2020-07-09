#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int t;
int s, c, r;
int arr[MAXN];

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &s, &c, &r);
		for (int i = 0; i < s; i++)
			scanf ("%d", &arr[i]);
		sort (arr, arr+s);
		for (int i = 0; i < c; i++)
			arr[i] += r;
		double ans = 0;
		for (int i = 0; i < s; i++)
			ans += (double)1/arr[i];
		printf ("%0.2lf\n", ans);
	}

	return 0;
}
