#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int t, n, k;
int qnt;
int arr[MAXN];

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %d", &n, &k);
		qnt = 0;
		arr[n]++;
		while (qnt < k) {
			while (!arr[n]) n--;
			qnt++;
			arr[n]--;
			arr[n/2]++;
			arr[(n-1)/2]++;
		}
		for (int i = n; i >= 0; i--)
			arr[i] = 0;

		printf ("Case #%d: %d %d\n", i, n/2, (n-1)/2);
	}

	return 0;
}
