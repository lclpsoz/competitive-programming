#include <bits/stdc++.h>
using namespace std;

int i;
int q, e, n;
set <int> offices;

int main ()
{
	scanf ("%d %d", &q, &e);
	for (i = 0; i < e; i++) {
		scanf ("%d", &n);
		offices.insert (n);
	}
	for (i = 0; i < q; i++) {
		scanf ("%d", &n);
		if (offices.find (n) != offices.end())
			printf ("0\n");
		else
			printf ("1\n");
		offices.insert (n);
	}
	return 0;
}
