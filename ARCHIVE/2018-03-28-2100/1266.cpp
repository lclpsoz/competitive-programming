#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int n, x, arr[MAXN], pos;

int main ()
{
	scanf ("%d", &n);
	while (scanf ("%d", &n), n) {
		x = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &arr[i]);
			if (arr[i]) {
				x++;
				pos = i;
			}
		}
		if (x == 0)
			printf ("%d\n",(n+1)/2);
		else {
			int bef = 1;
			for (int i = pos-1; i != pos;) {
				if (i == 0)
					i = n-1;
				else
					i--;
				if (bef == 1)
				if (arr[i] == 0)
					x = 1;

			}
		}



	}

	return 0;
}
