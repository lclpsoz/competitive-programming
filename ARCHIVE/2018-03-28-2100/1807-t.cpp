#include <bits/stdc++.h>
using namespace std;

long long unsigned mod = (1LL << 31)-1;
long long unsigned ans = 1;
int r;

int main ()
{
	scanf ("%d", &r);
	for (int i = 0; i < r; i++) {
		ans = (ans*3)%mod;
	}
	printf ("%llu\n", ans);
	return 0;
}
