#include <bits/stdc++.h>
using namespace std;

int t, n;
int x, qnt, maxi, ans;

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		maxi = -1;
		bool cont = false;
		ans = qnt = 0;
		for (int j = 0; j < n; j++) {
			scanf ("%d", &x);
			if (x > maxi) {
				maxi = x;
				qnt = 1;
				ans = 1;
				cont = true;
			}
			else if (x == maxi && cont)
				qnt++;
			else if (x == maxi && !cont) {
				qnt = 1;
				cont = true;
			}
			else
				cont = false;
			ans = max (qnt, ans);
		}
		printf ("Caso #%d: %d\n", i+1, ans);
	}

	return 0;
}
