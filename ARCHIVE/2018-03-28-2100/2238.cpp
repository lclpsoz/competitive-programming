#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main ()
{
	scanf ("%d %d %d %d", &a, &b, &c, &d);

	bool ans = false;
	for (int i = a; !ans && i <= c; i+=a)
		if (c%i == 0 && i%b != 0 && d%i != 0) {
			printf ("%d\n", i);
			ans = true;
		}

	if (!ans)
		printf ("-1\n");


	return 0;
}
