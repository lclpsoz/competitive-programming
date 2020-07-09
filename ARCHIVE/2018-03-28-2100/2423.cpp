#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main ()
{
	scanf ("%d %d %d", &a, &b, &c);
	a /= 2;
	b /= 3;
	c /= 5;
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	printf ("%d\n", a);
	return 0;
}
