#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int a, b;
int i;
long long ans;

int main ()
{
	while (scanf ("%d %d", &a, &b) != EOF) {
		ans = 1;
		for (i = a; i > (a-b); i--) {
			if (!(i%MOD))
				continue;
			ans *= i;
			while (!(ans%10))
				ans /= 10;
			ans %= 100;
		}
		printf ("%lld\n", ans%10);
	}
	return 0;
}
