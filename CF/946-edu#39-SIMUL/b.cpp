#include <bits/stdc++.h>
using namespace std;

long long ans, n, m;

int main ()
{
	scanf ("%lld %lld", &n, &m);

	if (n && m) {
		if (n > m)
			n%=2*m;
		else
			m%=2*n;
	}

	while (n && m) {
		// printf ("%lld %lld\n", n, m);
		if (n >= m<<1L)
			n%=2*m;
		else if (m >= n<<1L)
			m%=2*n;
		else
			break;

	}
	printf ("%lld %lld\n", n, m);
	return 0;
}
