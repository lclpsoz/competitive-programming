#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int t, n, l;
int arr[MAXN];
int perc[MAXN];
int total;

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %d", &n, &l);
		total = 0;
		for (int j = 0; j < l; j++) {
			scanf ("%d", &arr[j]);
			perc[j] = (arr[j]*10000)/n;
			if (perc[j]%100 >= 50)
				perc[j] = (perc[j]/100)+1;
			else
				perc[j] = perc[j]/100;
			total += perc[j];
		}
		printf ("%d\n", total);
		for (int j = 0; j < l; j++) {

		}
	}

	return 0;
}
