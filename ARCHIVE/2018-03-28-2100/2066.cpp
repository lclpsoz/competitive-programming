#include <bits/stdc++.h>
using namespace std;

int n;

long long pot10 (int e)
{
	if (e < 0)
		return 0;
	long long r = 1;
	while (e--)
		r*=10;
	return r;
}

int main ()
{
	long long ans[20];
	ans[1] = 0;
	for (int i = 2; i <= 18; i+=2) {
		long long x = 0;
		x = 36*pot10(i-2);
		int j = 0;
		long long y = pot10 (((i-4)/2)+1)/9;
		x += 9*45*y*pot10((i-4)/2);

		ans[i] = x;
		ans[i+1] = x*10;
	}

	scanf ("%d", &n);
	printf ("%lld\n", ans[n]);

	return 0;
}
