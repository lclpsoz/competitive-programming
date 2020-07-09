#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e6+10;

long long n;
long long ans;
long long arr[50];

long long pow2 (int x)
{
	return 1LL<<x;
}

int lg2 (long long x)
{
	return 63-__builtin_clzll (x);
}

void val_pow_2 (int x)
{
	arr[0] = 0;
	for (int i = 1; i <= x; i++)
		arr[i] = 2*arr[i-1] + pow2(i-1);
}

long long func (long long x)
{
	if (x == 0)
		return 0;
	if (__builtin_popcountll (x) == 1)
		return arr[lg2 (x)];
	else {
		long long y = pow2(lg2(x));
		// printf ("%lld %lld\n", x, y);
		return arr[lg2(y)] + y + func (x-y);
	}
}

int main ()
{
	srand(clock());
	scanf ("%lld", &n);
	val_pow_2 (lg2(n));
	printf ("%lld\n", func (n));

	return 0;
}
