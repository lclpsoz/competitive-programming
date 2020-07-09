#include <bits/stdc++.h>
using namespace std;

int n, k;
int y;
vector<int> comp;

int main ()
{
	scanf ("%d %d", &n, &k);
	while (n--) {
		scanf ("%d", &y);
		comp.push_back (y);
	}
	comp.push_back ((int)2e9);
	sort (comp.begin(), comp.end());
	if (k == 0) {
		if (comp[0] == 1)
			printf ("-1\n");
		else
			printf ("1\n");
	}
	else if (comp[k-1] != comp[k])
		printf ("%d\n", comp[k-1]);
	else
		printf ("-1\n");

	return 0;
}
