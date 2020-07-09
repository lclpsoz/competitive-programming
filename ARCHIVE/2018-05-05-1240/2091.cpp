#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

long long arr[MAXN];

int main ()
{
	int n;
	long long x;
	bool test;
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++)
			scanf ("%lld", &arr[i]);
		sort (arr, arr+n);
		arr[n] = -1;
		int i = 0;
		x = arr[0];
		test = false;
		while (1) {
			if (arr[i] == x) test = !test;
			else if (test) break;
			else {
				x = arr[i];
				test = true;
			}
			i++;
		}
		printf ("%lld\n", x);
	}

	return 0;
}
