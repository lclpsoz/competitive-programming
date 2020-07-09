#include <bits/stdc++.h>
using namespace std;

int n, base, now;
int i, j;
int mat[12][12];

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf ("%d", &mat[i][j]);

	base = 0;
	for (i = 0; i < n; i++)
		base += mat[0][i];

	now = base;
	for (i = 0; i < n && now == base; i++) {
		now = 0;
		for (j = 0; j < n; j++)
			now += mat[i][j];
	}
	for (i = 0; i < n && now == base; i++) {
		now = 0;
		for (j = 0; j < n; j++)
			now += mat[j][i];
	}
	if (now != base)
		now = -1;
	else {
		now = 0;
		for (i = 0; i < n; i++)
			now += mat[i][i];
		if (now != base)
			now = -1;
		else {
			now = 0;
			for (i = 0, j = n-1; i < n; i++, j--)
				now += mat[i][j];
		}
	}
	printf ("%d\n", now);
	return 0;
}
