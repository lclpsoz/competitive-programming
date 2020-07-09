#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int i, j, k;
int x, v;
int arr[MAXN];

int main ()
{
	for (i = 1; i <= 30; i++) {
		x = i;
		k = 0;
		while (x) {
			for (j = 0; j < x && (k+x) < MAXN; j++) {
				k+=x;
				if (!arr[k])
					arr[k] = i;
			}
			x--;
		}
	}
	/*for (i = 1; i < 1010; i++)
		printf ("%4d: %2d\n", i, arr[i]);*/
	while (scanf ("%d %d", &x, &v), x || v) {
		if (arr[x] && arr[x] <= v)
			printf ("possivel\n");
		else
			printf ("impossivel\n");
	}

	return 0;
}
