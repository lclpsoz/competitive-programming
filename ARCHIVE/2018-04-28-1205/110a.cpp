#include <bits/stdc++.h>
using namespace std;

int main ()
{
	char c = '-';
	int n = 0;
	while (c != EOF && c != '\n') {
		c = getchar ();
		if (c == '4' || c == '7')
			n++;
	}
	n%=10;
	if (n == 4 || n == 7)
		printf ("YES\n");
	else
		printf ("NO\n");

	return 0;
}
