#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int n;
int i, arr[MAXN];
long long sumi, avr, maxi, mini, x, ans;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		sumi = 0;
		for (i = 0; i < n; i++) {
			scanf ("%lld", &x);
			arr[i] = x;
			sumi+=x;
		}
		if (sumi%n)
			printf ("-1\n");
		else {
			avr = sumi/n;
			ans = 0;
			for (i = 0; i < n && avr-arr[i] > 0; i++)
				ans += avr-arr[i];
			printf ("%lld\n", abs(ans)+1);
		}
	}
	return 0;
}
