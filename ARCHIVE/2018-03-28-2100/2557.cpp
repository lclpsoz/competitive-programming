#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main ()
{
	while (scanf ("%d%*[/+]%d%*[/=]=%d%*[/\n]\n", &a, &b, &c) != EOF) {
		printf ("%d %d %d\n", a, b, c);
		if (!a)
			printf ("%d\n", b-c);
		else if (!b)
			printf ("%d\n", a-c);
		else
			printf ("%d\n", a+b);
		for (int j = 0; j < 1e8; j++);
	}
	return 0;
}
