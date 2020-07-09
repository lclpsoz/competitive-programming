#include <bits/stdc++.h>
using namespace std;

long long unsigned n;

int main ()
{

	while (scanf ("%llu", &n), n != -1) {
		if (n > 0)
			printf ("%llu\n", n-1);
		else
			printf ("0\n");
	}
	return 0;
}
