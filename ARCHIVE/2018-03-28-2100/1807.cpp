#include <bits/stdc++.h>
using namespace std;

long long unsigned mod = (1LL << 31)-1;
long long unsigned ans = 1, ansExt = 1,expp;
int r;

int main ()
{
	scanf ("%d", &r);
	ans = 3;
	expp = r;
	while (expp > 0) {
		if (expp & 1)
			ansExt = (ansExt*ans)%mod;
		ans = (ans*ans)%mod;
		expp >>= 1;
	}
	printf ("%llu\n", ansExt);
	return 0;
}
