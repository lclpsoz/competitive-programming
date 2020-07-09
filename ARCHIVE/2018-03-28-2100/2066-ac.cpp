
#include <bits/stdc++.h>
using namespace std;

int n;

long long pot10 (int e)
{
	long long r = 1;
	while (e--)
		r*=10;
	return r;
}

int main ()
{
	long long ans[20];
	ans[1] = 0;
	ans[2] = 36;
	ans[3] = ans[2]*10;
	for (int i = 4; i <= 18; i+=2) {
		int j = 0;
		long long x = 0;
		while (j < i-2) {
			x = 45*pot10(j) + 10*x;
			j+=2;
		}
		x = 36*pot10(j) + 9*x;

		ans[i] = x;
		ans[i+1] = x*10;
	}

	scanf ("%d", &n);
	printf ("%lld\n", ans[n]);

	return 0;
}
