#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	scanf ("%d %d %d", &a, &b, &c);
	if ((b+c) <= a)
		printf ("Farei hoje!\n");
	else
		printf ("Deixa para amanha!\n");
	return 0;
}
