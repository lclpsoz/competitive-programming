#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

int main ()
{
	scanf ("%lld %lld %lld", &a, &b, &c);
	if (a >= (b+c) || b >= (a+c) || c >= (a+b))
		printf ("n\n");
	else {
		a *= a;
		b *= b;
		c *= c;
		if (a == (b+c) || b == (a+c) || c == (a+b))
			printf ("r\n");
		else if (a > (b+c) || b > (a+b) || c > (a+b))
			printf ("o\n");
		else
			printf ("a\n");

	}
	return 0;
}
