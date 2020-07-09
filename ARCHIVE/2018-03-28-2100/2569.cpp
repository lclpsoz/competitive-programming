#include <bits/stdc++.h>
using namespace std;

int conv (int a)
{
	int aux = a;
	int e = 0;
	while (aux) {
		if ((aux%10) == 7)
			a -= 7 * pow(10, e);
		aux /= 10;
		e++;
	}
	return a;
}

int main ()
{
	int a, b, r;
	char c;
	scanf ("%d %c %d", &a, &c, &b);
	a = conv (a);
	b = conv (b);
	if (c == '+')
		r = conv (a+b);
	else
		r = conv (a*b);
	printf ("%d\n", r);

	return 0;
}
